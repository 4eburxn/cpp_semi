#include<cmath>


struct Vec2d
{
public:
    double x{.0};
    double y{.0};
    Vec2d() = default;
    Vec2d(double x_, double y_) : x{x_}, y{y_}{}

    Vec2d  operator+(const Vec2d&);
    Vec2d  operator-(const Vec2d&);
    Vec2d& operator+=(const Vec2d&);
    Vec2d& operator-=(const Vec2d&);
    bool operator==(const Vec2d&);
    bool operator!=(const Vec2d&);
    double lenth();
};

Vec2d operator*(const Vec2d&, double);
Vec2d operator*(double, const Vec2d&);
double operator*(const Vec2d&, const Vec2d&);