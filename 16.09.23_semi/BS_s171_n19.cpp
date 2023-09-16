#include<iostream>
#include<vector>
#include<string>



int main(){
    std::vector<int> scores;
    std::vector<std::string> names;
    scores.reserve(500);
    names.reserve(500);
    
    std::string namebuff = "";
    int numbuff=0;
    while(true){
        std::cin >>namebuff>>numbuff;
        scores.push_back(numbuff);
        names.push_back(namebuff);

        if(namebuff == "NoName" && numbuff == 0){
            break;
        }
    }
    for(size_t i = 0; i<scores.size()-1;i++){
        for(size_t j = i+1;j<scores.size();j++){
            if(names[i]==names[j]){
                std::cout << "имя " << names[j] << " указано 2 раза\n";
                return 1;
            }
        }
    }
    for(size_t i = 0;i<scores.size();i++){
        std::cout<<names[i]<<"\t"<<scores[i]<<std::endl;
    }


    return 0;
}