#include "PlayerComponent.h"
#include "../Renderer/Text.h"
#include "../Input/InputSystem.h"
#include "../Engine.h"
#include "../FrameWork/Actor.h"
#include "PhysicsComponent.h"
#include "AudioComponent.h"

#include <iostream>

namespace neu
{
	void PlayerComponent::Initialize()
	{
		auto component = m_owner->GetComponent<CollisionComponent>();
		if (component)
		{
			component->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
			component->SetCollisionExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}

	void PlayerComponent::Update()
	{
		// Movement
		if (g_inputSystem.GetKeyState(key_left) == InputSystem::Held)
		{
			m_owner->m_transform.rotation -= 180 * timer.deltaTime;
		}
		if (g_inputSystem.GetKeyState(key_right) == InputSystem::Held)
		{
			m_owner->m_transform.rotation += +180 * timer.deltaTime;
		}

		float thrust = 0;
		if (g_inputSystem.GetKeyState(key_up) == InputSystem::Held)
		{
			thrust = 100;
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();

		if (component)
		{
			// Thrust Force
			Vector2 force = Vector2::Rotate({ 1, 0 }, neu::DegToRad(m_owner->m_transform.rotation)) * thrust;
			component->ApplyForce(force);

			//component->ApplyForce(direction * speed);

			// Gravity
			force = (Vector2{ 400,300 } - m_owner->m_transform.position).Normalized() * 60.0;
			component->ApplyForce(force);
		}

		// 
		if (g_inputSystem.GetKeyState(key_space) == InputSystem::Held)
		{
			auto component = m_owner->GetComponent<AudioComponent>();
			if (component) component->Play();
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);
		 
		return true;
	}

	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		std::cout << "Player Enter" << std::endl;
	}
	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		std::cout << "Player Exit" << std::endl;
	}
}