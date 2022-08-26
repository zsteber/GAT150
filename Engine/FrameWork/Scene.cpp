#include "Scene.h"
#include "Factory.h"
#include <iostream>
#include <Core/Logger.h>


namespace neu
{
	Scene::Scene(const Scene& other)
	{
	}

	void Scene::Initialize()
	{
		for (auto& actor : m_actor) { actor->Initialize();}
	}

	void Scene::RemoveAll()
	{
		m_actor.clear();
	}

	void Scene::Update()
	{
		auto iter = m_actor.begin();
		while (iter != m_actor.end())
		{
			(*iter)->Update();
			if ((*iter)->m_destroy)
			{
				iter = m_actor.erase(iter);
			}
			else
			{
				iter++;
			}
		}

		// check collision
		for (auto iter1 = m_actor.begin(); iter1 != m_actor.end(); iter1++)
		{
			for (auto iter2 = m_actor.begin(); iter2 != m_actor.end(); iter2++)
			{
				if (iter1 == iter2) continue;

				float radius = (*iter1)->GetRadius() + (*iter2)->GetRadius();
				float distance = (*iter1)->m_transform.position.Distance((*iter2)->m_transform.position);

				if (distance < radius)
				{
					(*iter1)->OnCollision(iter2->get());
					(*iter2)->OnCollision(iter1->get());
				}
			}
		}
	}


	void Scene::Draw(Renderer& renderer)
	{
		for (auto& actor : m_actor)
		{
			actor->Draw(renderer);
		}
	}

	bool Scene::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool Scene::Read(const rapidjson::Value& value)
	{
			if (!(value.HasMember("actors")) || !value["actors"].IsArray())
			{
				return false;
			}

			for (auto& actorValue : value["actors"].GetArray())
			{
				std::string type;
				READ_DATA(actorValue, type);

				auto actor = Factory::Instance().Create<Actor>(type);
				if (actor)
				{
					//read actor
					actor->Read(actorValue);
					Add(std::move(actor));

					bool Prefab = false;
					READ_DATA(actorValue, Prefab);

					if (Prefab)
					{
						std::string name = actor->GetName();
						Factory::Instance().RegisterPrefab(name, std::move(actor));
					}
					else
					{
						Add(std::move(actor));
					}
				}
			}
			return true;
	}


	void Scene::Add(std::unique_ptr<Actor> actor)
	{
		actor->m_scene = this;
		m_actor.push_back(std::move(actor));
	}
}