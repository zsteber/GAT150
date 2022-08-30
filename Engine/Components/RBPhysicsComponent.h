#pragma once
#include "PhysicsComponent.h"
#include "Physics/PhysicsSystem.h"

namespace neu
{

	class RBPhysicsComponent : public PhysicsComponent
	{
		CLASS_DECLARATION(RBPhysicsComponent);

		RBPhysicsComponent() = default;
		~RBPhysicsComponent();

		void Initialize() override;

		virtual void ApplyForce(const Vector2& force);
		void Update() override;
		bool Write(const rapidjson::Value& value) const override;
		bool Read(const rapidjson::Value& value) override;

		friend class CollisionComponent;

	private:
		PhysicsSystem::RigidBodyData data;
		b2Body* m_body = nullptr;
	};
}