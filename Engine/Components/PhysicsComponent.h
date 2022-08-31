#pragma once
#include "../Framework/Component.h"
#include "../Math/Vector2.h"

namespace neu
{
	class PhysicsComponent : public Component
	{
	public:
		CLASS_DECLARATION(PhysicsComponent)

		PhysicsComponent() = default;

		void Update() override;
		bool Write(const rapidjson::Value& value) const;
		bool Read(const rapidjson::Value& value);
		virtual void ApplyForce(const Vector2& force) { acceleration += force; }

		virtual void Initialize() override {}

		Vector2 velocity;
		Vector2 acceleration;

		float damping = 1;
	};
}