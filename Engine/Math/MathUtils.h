#pragma once

namespace neu
{

	const float Pi = 3.14159265f;
	const float TwoPi = 6.2832185f;
	const float HalfPi = 1.57079633f;

	inline float DegToRad(float degrees)
	{
		return degrees * (Pi / 180);
	}

	inline float RadtoDeg(float radians)
	{
		return radians * (180 / Pi);
	}


	int sqr(int v);
	inline int half(int v) { return v / 2; }
}
