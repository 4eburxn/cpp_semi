#include<iostream>
#include<vector>

struct Point{
    long double x,y;
    Point() = default;
    Point(long double xx, long double yy): x{xx}, y{yy} {}

};

std::istream& operator>>(std::istream& is, Point& p){
    return is >> p.x >> p.y;
}

int main(){
    // Point p;
    // std::cin>>p;
    int a = 5;
    int& ref = a;
    ref = 10;
    std::cout << a << std::endl;
}