#pragma once
#include "PhysicsComponent.h"

namespace neu
{

	class RBPhysicsComponent : public PhysicsComponent
	{
		RBPhysicsComponent() = default;
		~RBPhysicsComponent() = default;

		void Initialize() override;

		virtual void ApplyForce(const Vector2& force) { acceleration += force; }
		void Update() override;
		bool Write(const rapidjson::Value& value) const override;
		bool Read(const rapidjson::Value& value) override;

	private:
		PhysicsComponent::RigidBodyData data;
		b2Body* m_body = nullptr;

	};
}