#include "Math/Transform.h"

namespace neu
{
	bool Transform::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool Transform::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, position, scale, rotation);

		return true;
	}
}