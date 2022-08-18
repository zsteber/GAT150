#include "PhysicsComponent.h"
#include "../FrameWork/Actor.h"
#include "../Engine.h"
#include "../Math/Vector2.h"

namespace neu
{
	void PhysicsComponent::Update()
	{
		velocity += acceleration * timer.deltaTime;
		m_owner->m_transform.position += velocity * timer.deltaTime;
		velocity *= damping;

		acceleration = Vector2::zero;
	}
	bool PhysicsComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}
	bool PhysicsComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, damping);
		READ_DATA(value, velocity);
		READ_DATA(value, acceleration);

		return true;
	}

}