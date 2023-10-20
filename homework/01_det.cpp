#include<iostream>

int main(){
    int ans1 = 1,ans2=0,mult=1;
    char ch;
    for(char prev = '#';(std::cin>>ch)&&(ch=='0' || ch=='1'); prev = ch){
        ans1*=((prev != ch) ? mult : 1);
        ans2+=((prev != ch) ? mult-1 : 0);
        mult= (prev == ch ? mult+1 : 1);
    }


    
    std::cout <<"num of op:"<< ans2+mult-1<<std::endl;
    std::cout <<"num of unic ways:"<< ans1*mult<<std::endl;
    return 0;
}