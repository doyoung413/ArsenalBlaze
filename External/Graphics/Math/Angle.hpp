#pragma once

constexpr float PI = 3.1415926535897932384626433832795f;
constexpr float TWO_PI = 2.f * PI;
constexpr float HALF_PI = PI / 2.f;
constexpr float DegreeToRadian(float angle_in_degree) { return angle_in_degree * (PI / 180.0f); }