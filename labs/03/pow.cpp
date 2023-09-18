#include<iostream>
#include<cmath>
#include<string>
#include<utility>
#include<vector>
#include<limits>

/// @brief Power function
/// @param x
/// @param n
/// @return x in the powwer of n

double pow(double x, int n){
    if(n<0){
        x=1. / x;
        n = -n;
    }
    double res{1.};
    for(int i = 0;i<n;++i){
        res*=x;
    }
    return res;
}
/**
 * @brief Power function(recursive)
 * 
*/
double pow_r(double x,int n){
    if(n==0){
        return 1;
    }
    if (n<0){
        x = 1./x;
        n = -n;
    }
    return pow_r(x,n-1)*x;
}

/// @brief An optimised vercion of @ref pow_r(double, int)
/// @param x
/// @param n
/// @return x in the powwer of n
double pow_opt(double x, int n){
    if(n==0){
        return 1;
    }
    if (n<0){
        x = 1./x;
        n = -n;
    }
    if (n%2 == 0){
        return pow_opt(x*x,n/2);
    }
    return pow_opt(x*x,n/2)*x;
}


void test_pow(double x, const double tol){
    for(int n:{1,2,3,4,5,6,7,8}){
        std::cout << "x = "<<x<<", "
                  << "n = "<<n<<std::endl;
        double etalon = std::pow(x,n);
        std::cout << "std::pow " <<etalon<<std::endl;
        using func = double(*)(double, int);
        // func fun = NULL;
        #define FUN_NAME(function)  std::make_pair(func(function), std::string(#function))

        auto powers = {FUN_NAME(pow), FUN_NAME(pow_r), FUN_NAME(pow_opt)};

        #undef FUN_NAME

        for(auto [f, name]:powers){
            std::cout << name << "\t";
            double p = f(x,n);
            double diff = p - etalon;

            std::cout << p << "(difference is " << diff <<")" 
                      << "[" << (std::abs(diff) < tol*3 ? "OK" : "FALED")
                      << "]" << std::endl;
            
        }
        std::cout << std::endl;

}
}


int main(){
    constexpr double x = 1.12341; // могут быть вычислены на момент компиляции
    constexpr double tol = std::numeric_limits<double>::epsilon();
    std::cout <<tol<<std::endl; 
    test_pow(x,tol);

    
    
    return 0;
}
