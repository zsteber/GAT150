#pragma once
#include "../Math/Transform.h"
#include "Serialization/Serializable.h"

#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class);

namespace neu
{
	class GameObject
	{
	public:
		GameObject() = default;
		
		virtual std::unique_ptr<GameObject> Clone() = 0;
		virtual void Initialize() = 0;
		virtual void Update() = 0;
	};
}