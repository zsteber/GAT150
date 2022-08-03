#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"
#include "../Math/Transform.h"

namespace neu
{
	class Scene;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Model& model, const Transform& transform) :  GameObject { transform }, m_model { model } {}

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);

		virtual void onCollision(Actor* other) { }
		float getRadius() { return m_model.GetRadius() * m_transform.scale; }
		std::string& getTag() { return m_tag; }

		friend class Scene;

	protected:
		std::string m_tag;
		bool m_destroy = false;
		Vector2 m_velocity;
		float m_damping = 1;

		Scene* scene = nullptr;
		Model m_model;

	};
}