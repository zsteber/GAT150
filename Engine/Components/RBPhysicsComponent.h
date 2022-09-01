#pragma once
#include "PhysicsComponent.h"
#include "Physics/PhysicsSystem.h"

namespace neu
{

	class RBPhysicsComponent : public PhysicsComponent
	{
	public:
		RBPhysicsComponent() = default;
	
		CLASS_DECLARATION(RBPhysicsComponent)

		~RBPhysicsComponent();

		void Initialize() override;

		virtual void ApplyForce(const Vector2& force);
		void Update() override;
		bool Write(const rapidjson::Value& value) const override;
		bool Read(const rapidjson::Value& value) override;

		friend class CollisionComponent;

		b2Body* m_body = nullptr;
		PhysicsSystem::RigidBodyData data;
	private:
	};
}