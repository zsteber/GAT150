#pragma once
#include "GameObject.h"
#include "Component.h"
#include "../Renderer/Model.h"
#include "../Math/Transform.h"
#include <vector>

namespace neu
{
	class Scene;
	class Renderer;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Transform& transform) : m_transform{ transform } {}

		virtual void Update();
		virtual void Draw(Renderer& renderer);

		void AddComponent(std::unique_ptr<Component> component);
		template<typename T>
		T* GetComponent();

		virtual void onCollision(Actor* other) { }
		float getRadius() { return 0; } // m_model.GetRadius()* std::max(m_transform.scale.x, m_transform.scale.y);
	
		std::string& getTag() { return m_tag; }

		Transform m_transform;
		friend class Scene;

		
		
	protected:
		std::string m_tag;
		bool m_destroy = false;
		Vector2 m_velocity;
		float m_damping = 1;

		
		Scene* scene = nullptr;

		std::vector<std::unique_ptr<Component>> m_component;
	};

	template<typename T>
	inline T* Actor::GetComponent()
	{
		for (auto& component : m_component)
		{
			T* result = dynamic_cast<T*>(component.get());
			if (result) return result;
		}
		return nullptr;
	}
}