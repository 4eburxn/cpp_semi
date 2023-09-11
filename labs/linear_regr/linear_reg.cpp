#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iterator>


struct Point{
    long double x,y;
    Point() = default;
    Point(long double xx, long double yy): x{xx}, y{yy} {}

};

std::istream& operator>>(std::istream& is, Point& p){
    return is >> p.x >> p.y;
}
std::ostream& operator<<(std::ostream& os, Point const& p){
    return os << p.x << "\t" << p.y;
}

std::vector<Point> read(std::string const& filename){
    std::ifstream ifs(filename);
    if(!ifs){
        throw std::runtime_error("Can not open file '"+ filename + "'");
        return std::vector<Point>();
    }
    return std::vector<Point>(std::istream_iterator<Point>(ifs),
                              std::istream_iterator<Point>());
}

struct Coeff{
    long double value,
                delta;
    Coeff(long double v,long double d):value{v}, delta{d}{};

};


std::tuple<Coeff,Coeff> least_square(std::vector<Point> const& points){
    std::size_t N = points.size();
    long double x_ave = 0., x2_ave = 0.,
                y_ave = 0., xy_ave = 0.;
    for(auto& p:points){
        x_ave  += p.x;
        x2_ave += p.x*p.x;
        y_ave  += p.y;
        xy_ave += p.x*p.y;
    }
    x_ave  /=N;
    x2_ave /=N;
    y_ave  /=N;
    xy_ave /=N;
    long double k = (xy_ave-x_ave*y_ave)/(x2_ave - x_ave*x_ave);
    long double b = y_ave-k*x_ave;

    return std::tuple<Coeff,Coeff>(Coeff(k,0.),Coeff(b,0.));
}

int main(int argc, char *argv[]){
    if(argc != 2){
        std::cerr << "usage: " << argv[0] << " file_name" << std::endl;
        return 2;
    }
    try {
        std::string filename(argv[1]);
        auto [k,b] = least_square(read(filename));
        std::cout << filename << "\nk,delta_k:" << k.value << ",\t" << k.delta << "\n"<<
                                   "b,delta_b:" << b.value << ",\t" << b.delta << std::endl;
    }
    catch (std::exception& e){
        std::cerr << "error: " << e.what() << std::endl;
        return 1;
    }



    return 0;
}