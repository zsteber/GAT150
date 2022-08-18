#include "Scene.h"
#include <algorithm>

#include <iostream>
#include <Instance.h>
#include <Core/Logger.h>

namespace neu
{
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
		for (auto iter1 = m_actor.begin(); iter1 != m_actor.end(); iter1++)
		{
			for (auto iter2 = m_actor.begin(); iter2 != m_actor.end(); iter2++)
			{
				if (iter1 == iter2) continue;

				float radius = (*iter1)->getRadius() + (*iter2)->getRadius();
				float distance = (*iter1)->m_transform.position.Distance((*iter2)->m_transform.position);

				if (distance < radius)
				{
					(*iter1)->onCollision(iter2->get());
					(*iter2)->onCollision(iter1->get());
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
		if (!value.HasMember("actors") || !value["actors"].IsArray())
		{
			LOG("Error reading file, neither an Actor nor Array");
			return false;
		}

		//read actors
		for (auto& actorValue : value["actors"].GetArray())
		{
			std::string type;
			READ_DATA(actorValue, type);

			auto actor = Factory::Instance().Create<Actor>(type);
			if (actor)
			{
				actor->Read(actorValue);
				Add(std::move(actor));
			}
		}

		return true;
	}


	void Scene::Add(std::unique_ptr<Actor> actor)
	{
		actor->scene = this;
		m_actor.push_back(std::move(actor));
	}
}