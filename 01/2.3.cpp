#include "std_lib_facilities.h"

int main ()
{
    long double k=1750,b1=1,b2,e = 2.7182818284;
    for(long double i = 1;i<k+1;i+=1){
        b1*=i;
    }
    cout<<k/pow(b1,1/k)<<endl;
    return 0;
}