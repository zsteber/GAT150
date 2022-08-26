#pragma once
#include "Physics/PhysicsSystem.h"
#include "box2d/b2_body.h"
#include "box2d/b2_contact.h"

namespace neu
{
	class ContactListener : public b2ContactListener
	{
	public:

		void BeginContact(b2Contact* contact) override;
		void EndContact(b2Contact* contact) override;
	};
}