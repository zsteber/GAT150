#pragma once
#include "Framework/Component.h"
#include "Physics/Collision.h"
#include "Physics/PhysicsSystem.h"
#include <functional>

namespace neu
{
	class CollisionComponent : public Component, public Collision
	{
	public:
		CLASS_DECLARATION(CollisionComponent);

		using functionpr = std::function<void(Actor*)>;

		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void SetCollisionEnter(functionpr function) { enterFunction = function; }
		void SetCollisionExit(functionpr function) { exitFunction = function; }

	private:
		PhysicsSystem::CollisionData data;
		Vector2 scale_offset = Vector2{ 1, 1 };

		functionpr enterFunction;
		functionpr exitFunction;

	};
}