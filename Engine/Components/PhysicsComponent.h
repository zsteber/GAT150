#pragma once
#include "../Framework/Component.h"
#include "../Math/Vector2.h"

namespace neu
{
	class PhysicsComponent : public Component
	{
	public:

		PhysicsComponent() = default;

		void Update() override;
		void ApplyForce(const Vector2& force) { acceleration += force; }

		Vector2 velocity;
		Vector2 acceleration;

		float damping = 1;
	};
}