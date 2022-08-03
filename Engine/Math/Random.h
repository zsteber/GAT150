#pragma once
#include <random>

namespace neu
{
	inline void SeedRandom(int seed) { srand(seed); }

	inline int Random() { return rand(); }
	inline int Random(int max) { return Random() % max; } // EXCLUSIVE (max = 10 -> 0 - 9)
	inline int Random (int min, int max) { return min + Random() % ((max - min) + 1); } // INCLUSIVE

	inline float randomf() { return rand() / (float)RAND_MAX; } // 0.0 - 1.0
	inline float randomf(float max) { return randomf() * max; } // 0.0 - max
	inline float randomf(float max, float min) { return min + randomf(max - min); } // 0.0 - max

}