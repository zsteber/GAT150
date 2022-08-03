#pragma once
#include "Actor.h"
#include <list>
#include<memory>

namespace neu
{
	class Actor;
	class Renderer;

	class Scene
	{
	public:
		Scene() = default;
		~Scene() = default;

		void Update();
		void Draw(Renderer& renderer);

		void Add(std::unique_ptr<Actor> actor);

		template<typename T>
		T* GetActor();

	private:
		std::list < std::unique_ptr<Actor>> m_actor;

	};
	template<typename T>
	inline T* Scene::GetActor()
	{
		for (auto& actor : m_actor)
		{
			T* result = dynamic_cast<T*>(actor.get());
			if (result) return result;
		}
		return nullptr;
	}
}