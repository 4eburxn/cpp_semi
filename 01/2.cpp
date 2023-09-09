#include "std_lib_facilities.h"

int main ()
{
    long double kf=1,b1=1,b2,e = 2.7182818284;
    b2 = (e+1.0/e)/2;
    for(int i = 1;i<100000;i++){
        kf = kf/i/(++i);
        b1+=kf;

    }
    cout<<b1<<"\t"<<b2<<endl;
    return 0;
}