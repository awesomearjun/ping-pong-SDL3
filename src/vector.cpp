#include "vector.hpp"

#include <iostream>

Vector2f::Vector2f(float p_x, float p_y)
{
    x = p_x;
    y = p_y;
}

void Vector2f::print()
{
    std::cout << "X: " << x << ", " << "Y: " << y << std::endl;
}

Vector2f Vector2f::operator*(float const& p_other)
{
    Vector2f result;
    result.x = x * p_other;
    result.y = y * p_other;
    return result;
}

void Vector2f::operator+=(Vector2f const& p_other)
{
    x += p_other.x;
    y += p_other.y;
}