#pragma once
#include <cmath>
#include <sstream>
#include <string>


namespace neu
{
	struct Vector2
	{
		
		float x, y;

		Vector2() : x{0 }, y{0 } {}
		Vector2(float x, float y) : x{ x }, y{ y } {}
		Vector2(float v) : x{ v }, y{ v } {}
		Vector2(int x, int y) : x{ (float)x }, y{ (float)y } {}

		void Set(float x, float y) { this->x = x; this->y = y; }

		float operator [] (size_t index) const { return (&x)[index]; }
		float& operator [] (size_t index) { return (&x)[index]; }

		
		Vector2 Add(const Vector2& v) { return Vector2{ v.x + x, v.y + y }; }


		static const Vector2 one;
		static const Vector2 zero;
		static const Vector2 up;
		static const Vector2 right;
		static const Vector2 left;
		static const Vector2 down;


		//Functions
		float LengthSqr();
		float Length();
		float DistanceSqr(const Vector2& v);
		float Distance(const Vector2& v);

		Vector2 Normalized();
		void Normalize();

		float GetAngle();
		static Vector2 Rotate(const Vector2& v, float angle);

		// Arithmetic Operators
		Vector2 operator + (const Vector2& v) { return Vector2(x + v.x, y + v.y); }
		Vector2 operator - (const Vector2& v) const { return Vector2{ this->x - v.x, this->y - v.y }; }
		Vector2 operator * (const Vector2& v) { return Vector2(x * v.x, y * v.y); }
		Vector2 operator / (const Vector2& v) { return Vector2(x / v.x, y / v.y); }

		// Vector2 = Vector2 + float
		Vector2& operator += (const Vector2& v) { x += v.x, y += v.y; return *this; }
		Vector2& operator -= (const Vector2& v) { x -= v.x, y -= v.y; return *this; }
		Vector2& operator *= (const Vector2& v) { x *= v.x, y *= v.y; return *this; }
		Vector2& operator /= (const Vector2& v) { x /= v.x, y /= v.y; return *this; }
		
		// Assignment Operators
		Vector2 operator + (float s) { return Vector2(x + s, y + s); }
		Vector2 operator - (float s) const { return Vector2{ this->x - s, this->y - s }; }
		Vector2 operator * (float s) { return Vector2(x * s, y * s); }
		Vector2 operator / (float s) { return Vector2(x / s, y / s); }

		Vector2 operator += (float s) { return Vector2(x += s, y += s); }
		Vector2 operator -= (float s) { return Vector2(x -= s, y -= s); }
		Vector2 operator *= (float s) { return Vector2(x *= s, y *= s); }
		Vector2 operator /= (float s) { return Vector2(x /= s, y /= s); }

		//Unary
		// Vector2 == Vector2
		Vector2 operator - () { return Vector2{ -x, -y }; }

		//Comparison
		//Vector2 == Vector2
		bool operator == (const Vector2& v) const { return (this->x == v.x && this->y == v.y); }
		bool operator != (const Vector2& v) const { return (this->x != v.x || this->y != v.y); }

	};

	std::istream& operator >> (std::istream& stream, Vector2& v);
	
	
	std::ostream& operator << (std::ostream& stream, const Vector2& v);


	//Functions
	inline float Vector2::LengthSqr() { return x * x + y * y; }
	inline float Vector2::Length() { return std::sqrt(x * x + y * y); }

	inline float Vector2::DistanceSqr(const Vector2& v) 
	{
		return ((*this) - v).LengthSqr();
	}

	inline float Vector2::Distance(const Vector2& v)
	{
		return ((*this) - v).Length();
	}

	inline Vector2 Vector2::Normalized() 
	{
		float length = Length();

		return Vector2(x / length, y / length);
	}

	inline void Vector2::Normalize()
	{
		(*this) /= Length();
	}

	inline float Vector2::GetAngle()
	{
		return std::atan2(y, x);
	}

	inline Vector2 Vector2::Rotate(const Vector2& v, float angle)
	{
		float x = v.x * std::cos(angle) - v.y * std::sin(angle);
		float y = v.x * std::sin(angle) + v.y * std::cos(angle);

		return Vector2(x, y);
	}
}