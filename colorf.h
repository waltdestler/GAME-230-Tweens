#pragma once

#include <SFML/Graphics/Color.hpp>

using namespace sf;

struct ColorF
{
	float r, g, b, a;

	ColorF(float r, float g, float b, float a = 1)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	ColorF(Color color)
	{
		this->r = color.r / 255.0f;
		this->g = color.g / 255.0f;
		this->b = color.b / 255.0f;
		this->a = color.a / 255.0f;
	}

	operator Color()
	{
		return Color(
			(int)(r * 255),
			(int)(g * 255),
			(int)(b * 255),
			(int)(a * 255));
	}
};

inline ColorF operator+(ColorF c1, ColorF c2)
{
	return ColorF(
		c1.r + c2.r,
		c1.g + c2.g,
		c1.b + c2.b,
		c1.a + c2.a);
}

inline ColorF operator-(ColorF c1, ColorF c2)
{
	return ColorF(
		c1.r - c2.r,
		c1.g - c2.g,
		c1.b - c2.b,
		c1.a - c2.a);
}

inline ColorF operator*(ColorF c1, ColorF c2)
{
	return ColorF(
		c1.r * c2.r,
		c1.g * c2.g,
		c1.b * c2.b,
		c1.a * c2.a);
}

inline ColorF operator/(ColorF c1, ColorF c2)
{
	return ColorF(
		c1.r / c2.r,
		c1.g / c2.g,
		c1.b / c2.b,
		c1.a / c2.a);
}

inline ColorF operator+(ColorF c1, float f)
{
	return ColorF(
		c1.r + f,
		c1.g + f,
		c1.b + f,
		c1.a + f);
}

inline ColorF operator-(ColorF c1, float f)
{
	return ColorF(
		c1.r - f,
		c1.g - f,
		c1.b - f,
		c1.a - f);
}

inline ColorF operator*(ColorF c1, float f)
{
	return ColorF(
		c1.r * f,
		c1.g * f,
		c1.b * f,
		c1.a * f);
}

inline ColorF operator/(ColorF c1, float f)
{
	return ColorF(
		c1.r / f,
		c1.g / f,
		c1.b / f,
		c1.a / f);
}

inline ColorF operator+(float f, ColorF c2)
{
	return ColorF(
		f + c2.r,
		f + c2.g,
		f + c2.b,
		f + c2.a);
}

inline ColorF operator-(float f, ColorF c2)
{
	return ColorF(
		f - c2.r,
		f - c2.g,
		f - c2.b,
		f - c2.a);
}

inline ColorF operator*(float f, ColorF c2)
{
	return ColorF(
		f * c2.r,
		f * c2.g,
		f * c2.b,
		f * c2.a);
}

inline ColorF operator/(float f, ColorF c2)
{
	return ColorF(
		f / c2.r,
		f / c2.g,
		f / c2.b,
		f / c2.a);
}