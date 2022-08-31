#pragma once
#include "FrameWork/Actor.h"

namespace neu
{
	class Actor;

	class Collision
	{
	public:

		virtual void OnCollisionEnter(Actor* other) = 0;
		virtual void OnCollisionExit(Actor* other) = 0;
	};
}