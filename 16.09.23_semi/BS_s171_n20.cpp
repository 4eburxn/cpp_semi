#include<iostream>
#include<vector>
#include<string>

void fill_vectors(std::vector<std::string>& names, std::vector<int>& scores,std::vector<bool>& is_deleated){
    std::string namebuff = "";
    int numbuff=0;

    std::cin >>namebuff>>numbuff;
    while(namebuff != "NoName" || numbuff != 0){
        scores.push_back(numbuff);
        names.push_back(namebuff);
        is_deleated.push_back(false);
        std::cin >>namebuff>>numbuff;       
    }
}

void find_and_del_doubles(std::vector<std::string>& names, std::vector<int>& scores, std::vector<bool>& is_deleated){
    std::cout<<"\n\n";
    for(size_t i = 0; i<scores.size()-1;i++){
        for(size_t j = i+1;j<scores.size();j++){
            if(names[i]==names[j] && !is_deleated[i]){
                std::cout << "удален повтор " << names[j] << "\n";
                is_deleated[j] = true;
            }
        }
    }
}

void print_all(std::vector<std::string>& names, std::vector<int>& scores, std::vector<bool>& is_deleated){
    for(size_t i=0;i<names.size();i++){
        if(!is_deleated[i]){
            std::cout<<names[i]<<"\t"<<scores[i]<<std::endl;
        }
    }
}

int find_by_name(std::string namebuff,std::vector<std::string>& names, std::vector<int>& scores, std::vector<bool>& is_deleated){
    for(size_t i = 0; i<scores.size();i++){
        if(names[i] == namebuff && !is_deleated[i]){
            return i;
        }
    }
    return -1;

int find_by_score(int num,std::vector<std::string>& names, std::vector<int>& scores, std::vector<bool>& is_deleated){
    flag = true;
    for(size_t i = 0; i<scores.size();i++){
        if(scores[i] == num && !is_deleated[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    std::vector<int> scores;
    std::vector<std::string> names;
    std::vector<bool> is_deleated;

    bool flag;
    std::string namebuff = "";
    int numbuff=0;

    fill_vectors(names,scores,is_deleated);

    find_and_del_doubles(names,scores, is_deleated);

    std::cout<<"\n\n";
    print_all(names,scores, is_deleated);



    std::cin>>namebuff;
    while (namebuff != "NoName"){
        int i = find_by_name(namebuff,names,scores, is_deleated);
        if(i==-1){
            std::cout<<"Имя не найдено\n";
        }
        else{
            std::cout<<"\t"<<scores[i]<<std::endl;
        }
        std::cin>>namebuff;
    }


    std::cin>>numbuff;
    while (numbuff >-1){
        flag = true;
        for(size_t i = 0; i<scores.size();i++){
            if(scores[i] == numbuff){
                std::cout<<" "<<names[i]<<std::endl;
                flag = false;
            }
        }
        if(flag){
            std::cout<<"Балл не найден\n";
        }
        std::cin>>numbuff;
    }

    return 0;
}