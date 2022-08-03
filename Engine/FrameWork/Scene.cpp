#include "Scene.h"
#include <algorithm>

#include <iostream>

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


	void Scene::Add(std::unique_ptr<Actor> actor)
	{
		actor->scene = this;
		m_actor.push_back(std::move(actor));
	}
}