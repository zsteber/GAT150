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
}