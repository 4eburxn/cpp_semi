#include<iostream>

int main(){
    char A='0', ret=0, cnt=0;
    while(std::cin>>A && (A=='0' || A=='1')){
        for(cnt = 0;A=='1' && std::cin>>A;cnt++){}
        if (cnt) std::cin.putback(A);
        ret = (ret>cnt ? ret : cnt);
    }
    std::cout<<int(ret)<<std::endl;
    return 0;
}