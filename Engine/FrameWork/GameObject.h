#pragma once
#include "../Math/Transform.h"
#include "Serialization/Serializable.h"

namespace neu
{
	class GameObject
	{
	public:
		GameObject() = default;
		

		virtual void Update() = 0;
	};
}