#pragma once
#include "Actor.h"
#include <list>
#include<memory>
#include <FrameWork/Game.h>

namespace neu
{
	//class Actor;
	//class Renderer;
	//class game;

	class Scene : public ISerializable, public GameObject
	{
	public:
		Scene() = default;
		Scene(Game* game) : m_game{ game } {}
		~Scene() = default;

		virtual void Initialize() override;

		void Update() override;
		void Draw(Renderer& renderer);
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Add(std::unique_ptr<Actor> actor);

		template<typename T>
		T* GetActor();

		Game* GetGame() { return m_game; }

	private:
		std::list < std::unique_ptr<Actor>> m_actor;
		Game* m_game;

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