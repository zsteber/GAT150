#pragma once
#include "GameObject.h"
#include "FrameWork/Actor.h"

namespace neu
{
	class Actor;

	class Component : public GameObject, public ISerializable
	{

	public:

		Component() = default;
		~Component() = default;

		virtual void Initialize() override {}
		virtual void Update() = 0;

		friend class Actor;

		Actor* m_owner = nullptr;

	};
}