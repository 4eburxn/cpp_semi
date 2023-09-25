#include<iostream>
#include<cmath>
#include<string>
#include<utility>



double integrate_rectangle(double a,double b,double(*f)(double),int N){
    double h = (b-a) / N;
    double sum = 0.;
    for(int i = 0;i<N;i++){
        sum+=f(a+i*h);
    }
    return h*sum;
}

double integrate_trapecium(double a,double b,double(*f)(double),int N){
    double h = (b-a) / N;
    double sum = 0.;
    for(int i = 1;i<N;i++){
        sum+=f(a+i*h);
    }

    return h*(0.5*f(a)+sum+0.5*f(b));
}

double integrate_simpson(double a,double b,double(*f)(double),int N){
    double h = (b-a)/(2*N);
    double sum = 0.;
    for(int i = 1;i<=N;i++){
        sum +=4*f(a+(2*i-1)*h)+2*f(a+2*i*h);
    }
    return h/3.*(f(a)+sum+f(b));
}

int main(){
    std::cout<<integrate_simpson(0.,M_PI,std::sin,10000)<<std::endl;

    const double a = 0.;
    constexpr double b = 4. * std::atan(1.);
    const double exact = 2.;

    std::cout << "integr from " << a<<" to "<<b<<std::endl;
    using Func = double(*)(double ,double ,double(*)(double),int);
    #define FUN_NAME(function)\
        std::make_pair(Func(function), std::string(#function))
    auto iterators = {
        FUN_NAME(integrate_rectangle),
        FUN_NAME(integrate_trapecium),
        FUN_NAME(integrate_simpson)
    };
    #undef FUN_NAME

    std::cout.precision(15);

    for(int N:{1,10,100,1000,10000,10000}){
        std::cout<<"N ="<<N<<std::endl;
        for(auto it:iterators){
            double res = it.first(a,b,std::sin,N);
            std::cout<<it.second<<": "<<res
                     <<", err = "<<std::abs(res-exact)<<std::endl;
        }
    }

    return 0;
}