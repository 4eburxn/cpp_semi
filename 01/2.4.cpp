#include "std_lib_facilities.h"

int main ()
{
    long double k=10000,b1=1,b2,e = 2.7182818284;
    for(long double i = 1;i<k+1;i+=1){
        b1*=pow((i+1)/i,pow(2,-i+1));
    }
    cout<<b1<<endl;
    return 0;
}