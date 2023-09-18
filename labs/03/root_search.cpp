#include<iostream>
#include<cassert>


enum class SolveMethod{
    binary,
    hords,
    newton
};

struct SolveResult
{
    double root;
    bool valid;
    unsigned int stepNumber;
    SolveMethod method;

    SolveResult() = delete;
};

auto solver_binary(double a, double b,double eps,double (*f)(double)){
    assert(a<b && eps >0.);
    unsigned int steps = 0;
    double x;

    while(b-a>eps){
        x = .5*(a+b);
        if (f(x)*f(a)<0.){
            b = x;
        }
        else{
            a = x;
        }
        ++steps;
    }
    return SolveResult{x,true,steps,SolveMethod::binary};
}

auto solver_hords(double a, double b,double eps,double (*f)(double)){
    assert(abs(a-b)>0. && eps >0.);
    unsigned int steps = 0;
    
    while(abs(b-a)>eps){
        double fa = f(a);
        double fb = f(b);
        if(fb-fa == 0.){
            return SolveResult{b,false,steps,SolveMethod::hords};
        }
        double temp = b;
        b = a-fa*(b-a)/(fb-fa);
        a = temp;
        ++steps;
    }
    return SolveResult{b,true,steps,SolveMethod::hords};
}

auto solver_newton(double a, double b,double eps,double (*f)(double)){
    assert(abs(a-b)>0. && eps >0.);
    unsigned int steps = 0;
    double dx = eps* .1;
    double x = .5*(a+b);

    double x0;
    do{
        x0 = x;
        double df = (f(x0+dx)-f(x0))/dx;
        if (df == 0){
            return SolveResult{b,false,steps,SolveMethod::newton};
        }
        x = x0-f(x0)/df;
    } while (abs(x-x0)>eps);
    return SolveResult{x,true,steps,SolveMethod::newton};
}


int main(){
    SolveMethod t = SolveMethod::binary;
}