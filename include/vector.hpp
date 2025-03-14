#pragma once

struct Vector2f
{
    int x, y;

    Vector2f() = default;    
    Vector2f(float p_x, float p_y);

    void print();

    Vector2f operator*(float const& p_other);
    void operator+=(Vector2f const &p_other);
};
