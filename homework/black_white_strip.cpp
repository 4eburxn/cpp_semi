#include<iostream>

char black = 'B';

int main(){
    char ch=0;
    int ans=0,n,k;
    for(std::cin>>n>>k;((n--)-ans*(k-1)>0)&&(std::cin>>ch);ans+=(ch==black)){
        std::cin.ignore((k-1)*(ch==black), '\n');
    }
    std::cout<<ans<<std::endl;

    return 0;
}