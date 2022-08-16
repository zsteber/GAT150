#pragma once

namespace neu
{

	constexpr float Pi = 3.14159265f;
	constexpr float TwoPi = 6.2832185f;
	constexpr float HalfPi = 1.57079633f;

	constexpr float DegToRad(float degrees)
	{
		return degrees * (Pi / 180);
	}

	constexpr float RadtoDeg(float radians)
	{
		return radians * (180 / Pi);
	}

	int sqr(int v);
	inline int half(int v) { return v / 2; }
}
