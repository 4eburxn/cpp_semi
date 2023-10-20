#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<cmath>
#include<iterator>


#include"randtemp.h"


struct Record
{
    int hour;
    double temperature;
};

std::istream& operator>>(std::istream& is, Record rec){
    int h;
    double t;
    if(is>>h>>t){
        rec = Record{h,t};
    }

    return is;
}


std::ostream& operator<<(std::ostream& is, Record rec){
    is<<rec.hour<<"\t"<<rec.temperature;
    return is;
}


auto generate_temps(std::size_t n){
    constexpr int n_hours = 24;
    constexpr double ave = 10.;
    constexpr double ampl = 5.;
    constexpr double phase = 6.-14.;
    constexpr double std_dev = .5;

    std::vector<Record> res{5};
    for(auto& r:res){
        r.hour = randint(n_hours-1);
        double mean = ave+ampl*sin(2.*M_PI*(r.hour+phase)/double(n_hours));
        r.temperature = normal(mean,std_dev);
    }
    return res;
}

auto read_from_file(std::string filename)
{
    std::ifstream ifs{filename};
    std::vector<Record> res;

    std::copy(std::istream_iterator<Record>(ifs),
                                 std::istream_iterator<Record>(),
                                 std::back_inserter(res));

    return res;
}

void write_to_file(const std::string filename){
    std::ofstream ofs{filename};
    if(!ofs){
        throw std::runtime_error("could not open file");
    }
    auto temps = generate_temps(5);

    std::copy(temps.begin(),temps.end(), std::ostream_iterator<Record>(ofs, "\n"));
}

int main(){
    write_to_file("labs/06/temp.txt");
    auto temps = read_from_file("labs/06/temp.txt");
    std::cout << randint(100);
    for(auto i:temps){
        std::cout<<i.hour<<"\t"<<i.temperature<<std::endl;
    }

    return 0;
}