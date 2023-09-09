#include "std_lib_facilities.h"

int main ()
{
    long double k=1,b1=1,b2,e = 2.7182818284;
    for(long double i = 1.0;i<10000000.0;i+=1.0){
        b1*=(4*i*i)/(4*i*i-1.0);
    }
    cout<<b1<<"\t"<<3.1415/2.0<<endl;
    return 0;
}