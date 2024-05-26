#pragma once
class [[nodiscard]] Color4f
{
public:
	float red = 0;
	float green = 0;
	float blue = 0;
	float alpha = 1.0f;

public:
	Color4f() noexcept = default;
	Color4f(float grey, float alpha = 1.0f) noexcept;
	Color4f(float red, float green, float blue, float alpha = 1.0f) noexcept;
};

static_assert(sizeof(Color4f) == 16, "Color4f should be 4 floats");

class Color4ub;
Color4f to_color4f(const Color4ub& eight_bit_color);
