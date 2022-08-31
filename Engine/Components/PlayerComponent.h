#pragma once
#include "../FrameWork/Component.h"
#include "Physics/Collision.h"

namespace neu
{

	class PlayerComponent : public Component, public Collision
	{

	public:
		CLASS_DECLARATION(PlayerComponent)

		PlayerComponent() = default;

		void Initialize() override;

		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		float speed = 0;
	};
}