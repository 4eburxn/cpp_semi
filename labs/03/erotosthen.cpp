#include<iostream>
#include<cassert>
#include<string>
#include<vector>
#include<stdexcept>


std::vector<int> eratosthen_sieve(int max){
    assert(max >1);
    max++;

    std::vector<bool> sieved(max+1,false);

    for(int i = 2;i*i<=max;++i){
        if(!sieved[i]){
            int sep = (i!=2) ? i*2 : i;
            for(int j = i*i;j<max;j+=sep){
                sieved[j] = true;
            }
        }
    }

    std::vector<int> primed;
    for(int i = 2;i<max;++i){
        if(!sieved[i]){
            primed.push_back(i);
        }
    }
    return primed;
}

bool is_prim(int x){
    for(int i = 2; i*i<x;i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}




int main(){
    for(int max:{2,3,4,5,6,1000,1001,997}){
        std::cout<<"max = "<<max<<"\n";
        for (auto p:eratosthen_sieve(max)){
            if(!is_prim(p)){
                throw std::runtime_error("not a prime ("+std::to_string(p)+")");
            }
            std::cout << p<<" ";
        }
        std::cout << std::endl;
    }

    return 0;
}