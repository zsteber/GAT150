#pragma once
#include "Actor.h"
#include <list>
#include <memory>

namespace neu
{

	class Scene : public GameObject, public ISerializable
	{
	public:

		Scene() = default;
		Scene(const Scene& other) {}
		~Scene() = default;

		CLASS_DECLARATION(Scene)

		void Initialize();
		void Update();

		void Draw(Renderer& renderer);
		void Add(std::unique_ptr<Actor> actor);

		void RemoveAll();

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		// Actor Getters
		template<typename T>
		T* GetActor();

		template<typename T = Actor>
		T* GetActorFromName(const std::string& name);

		template<typename T = Actor>
		std::vector<T*> GetActorsFromTag(const std::string& tag);

	private:

		std::list<std::unique_ptr<Actor>> m_actors;

	};

	template<typename T>
	inline T* Scene::GetActor()
	{
		for (auto& actor : m_actors)
		{
			T* result = dynamic_cast<T*>(actor.get());
			if (result) return result;
		}
		return nullptr;
	}

	template<typename T>
	T* Scene::GetActorFromName(const std::string& name)
	{
		for (auto& actor : m_actors)
		{
			if (name == actor->GetName())
			{
				return dynamic_cast<T*>(actor.get());
			}
		}
		return nullptr;
	}

	template<typename T>
	std::vector<T*> Scene::GetActorsFromTag(const std::string& tag)
	{
		std::vector<T*> result;

		for (auto& actor : m_actors)
		{
			if (tag == actor->GetTag())
			{
				T* tagActor = dynamic_cast<T*>(actor.get());
				if (tagActor)
				{
					result.push_back(std::move(tagActor));
				}
			}
		}
		return result;
	}

}