#include "vec2d.h"
#include<limits>

Vec2d Vec2d::operator+(const Vec2d& rhs)
{
    return Vec2d(x+rhs.x,y+rhs.y);
}

Vec2d Vec2d::operator-(const Vec2d& rhs)
{
    return Vec2d(x-rhs.x,y-rhs.y);
}

Vec2d& Vec2d::operator+=(const Vec2d & rhs)
{
    x+=rhs.x;
    y+=rhs.y;
    return *this;
}
Vec2d& Vec2d::operator-=(const Vec2d & rhs)
{
    x-=rhs.x;
    y-=rhs.y;
    return *this;
}

bool Vec2d::operator==(const Vec2d& rhs)
{
    constexpr double tol = std::numeric_limits<double>::epsilon()*2;
    return std::abs(x-rhs.x)+std::abs(y-rhs.y)>tol;
}

bool Vec2d::operator!=(const Vec2d& rhs) 
{ 
    return !(*this == rhs);
}

double Vec2d::lenth()
{
    return std::pow(x*x+y*y,0.5);
}

Vec2d operator*(const Vec2d& lhs, double rhs)
{
    return Vec2d(lhs.x*rhs, lhs.y*rhs);
}
Vec2d operator*(double lhs, const Vec2d& rhs)
{
    return Vec2d(rhs.x*lhs, rhs.y*lhs);
}

double operator*(const Vec2d &lhs, const Vec2d &rhs)
{
    return lhs.x*rhs.x+lhs.y*rhs.y;
}
