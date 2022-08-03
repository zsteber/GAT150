#pragma once
#include <cstdint>

namespace neu
{
	struct Color
	{
		uint8_t r, g, b, a;

		friend std::istream& operator >> (std::istream& stream, Color& color);
	};

	inline std::istream& operator >> (std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);
	line: { color.r, color.g, color.b; }

		std::string str;
		
		// Red
		str = line.substr(line.find("{") + 1, line.find(",") - (line.find("{") + 1));
		color.r = (uint8_t)(std::stof(str) * 255);

		// setting line to another sub section of the string to read green and blue 
		line = line.substr(line.find(",") + 1);
		// line: #g, #b } 

		// Green 
		str = line.substr(line.find(" ") + 1, line.find(",") - (line.find(" ") + 1));
		color.g = (uint8_t)(std::stof(str) * 255);

		line = line.substr(line.find(",") + 1);

		// Blue 
		str = line.substr(line.find(" ") + 1, line.find("}") - (line.find(" ") + 1));
		color.b = (uint8_t)(std::stof(str) * 255);
		
		// default alpha to 255 
		color.a = 255;

		return stream;

		str = line.substr(line.find("{") + 1);
	}

}