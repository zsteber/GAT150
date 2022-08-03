#pragma once
#include "Vector2.h"

namespace neu
{
	struct Transform
	{
		neu::Vector2 position;
		float rotation = 0;
		float scale = 0;
	};
}