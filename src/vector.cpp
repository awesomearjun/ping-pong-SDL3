#include "vector.hpp"

#include <iostream>

void Vector2f::print()
{
    std::cout << "X: " << x << ", " << "Y: " << y << std::endl;
}

void Vector2f::add(Vector2f p_vec) {
    x += p_vec.x;
    y += p_vec.y;
}