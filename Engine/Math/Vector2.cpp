#include "Vector2.h"

namespace neu
{
	const Vector2 zero{ 0, 0 };
	const Vector2 one{ 1, 1 };

	const Vector2 up{ 0, -1 };
	const Vector2 down{ 0, 1 };
	const Vector2 left{ -1, 0 };
	const Vector2 right{ 1, 0 };

	std::istream& operator >> (std::istream& stream, Vector2& v)
	{
		std::string line;
		std::getline(stream, line);

		// { ##, ##}
		std::string xstring = line.substr(line.find("{") + 1, line.find(",") - (line.find("{") - 1));
		v.x = std::stof(xstring);

		std::string ystring = line.substr(line.find(",") + 1, line.find("}") - (line.find(",") + 1));
		v.y = std::stof(ystring);

		return stream;
	}
	std::ostream& operator<<(std::ostream& stream, const Vector2& v)
	{
		stream << v.x << " " << v.y;

		return stream;
	}
}