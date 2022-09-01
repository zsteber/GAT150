#pragma once
#include "GameObject.h"
#include "Component.h"
#include "Math/Transform.h"
#include <vector>

namespace neu
{
	class Scene;
	class Renderer;

	class Actor : public GameObject, public ISerializable
	{
	public:
		Actor() = default;
		Actor(const Actor& other);
		Actor(const Transform& transform) : m_transform{ transform } {}

		CLASS_DECLARATION(Actor)

		virtual void Initialize() override;

		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void AddChild(std::unique_ptr<Actor> child);

		void AddComponent(std::unique_ptr<Component> component);

		template<typename T>
		T* GetComponent();

		std::string& GetTag() { return tag; }
		void SetTag(const std::string& tag) { this->tag = tag; }

		std::string& GetName() { return name; }
		void SetName(const std::string& name) { this->name = name; }

		void SetDestroy() { m_destroy = true; }
		bool IsDestroyed() { return m_destroy; }

		void SetActive(bool active = true) { m_active = active;	}
		bool IsActive() { return m_active;	}

		Scene* GetScene() {	return m_scene;	}

		friend class Scene;
		friend class Component;

		Transform m_transform;

	protected:
		std::string name;
		std::string tag;

		bool m_active = true;

		bool m_destroy = false;
		
		Scene* m_scene = nullptr;
		Actor* m_parent = nullptr;

		std::vector<std::unique_ptr<Component>> m_components;
		std::vector<std::unique_ptr<Actor>> m_children;
	};

	template<typename T>
	inline T* Actor::GetComponent()
	{
		for (auto& component : m_components)
		{
			T* result = dynamic_cast<T*>(component.get());
			if (result) return result;
		}

		return nullptr;
	}
}