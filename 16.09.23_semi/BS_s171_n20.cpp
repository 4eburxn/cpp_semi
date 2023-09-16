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
}


std::vector<int> find_by_score(int num,std::vector<std::string>& names, std::vector<int>& scores, std::vector<bool>& is_deleated){
    std::vector<int> ret;
    for(size_t i = 0; i<scores.size();i++){
        if(scores[i] == num && !is_deleated[i]){
            ret.push_back(i);
        }
    }
    return ret;
}



int main(){
    std::vector<int> scores;
    std::vector<std::string> names;
    std::vector<bool> is_deleated;

    bool flag;
    std::string namebuff = "";
    int numbuff=0;
    char chbuff;
    std::cin >> numbuff>> namebuff;
    std::cout << numbuff <<" "<< namebuff;
    return 0;
    fill_vectors(names,scores,is_deleated);

    find_and_del_doubles(names,scores, is_deleated);

    std::cout<<"\n\n";
    print_all(names,scores, is_deleated);


    std::cout<<"\n\nпоиск по имени \n";
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

    std::cout<<"\n\nпоиск по баллу \n";
    std::cin>>numbuff;
    while (numbuff >-1){
        std::vector<int> i = find_by_score(numbuff,names,scores, is_deleated);
        if(i.size() == 0){
            std::cout<<"Балл не найден\n";
        }
        for(auto j:i){
            std::cout <<"\t"<<names[j]<<std::endl;
        }
        std::cin>>numbuff;
    }

    std::cout<<"\n\nрежим изменений, введите \n<имя> [+/-/*/=] <число> \n";
    std::cin>>namebuff>>chbuff>>numbuff;
    while (namebuff != "NoName"){
        flag = true;
        int i = find_by_name(namebuff,names,scores, is_deleated);
        if(i==-1){
            std::cout<<"Имя не найдено\n";
        }
        else{
            switch (chbuff)  {
                case '+':
                    scores[i]+=numbuff;
                    break;
                case '-':
                    scores[i]-=numbuff;
                    break;
                case '*':
                    scores[i]*=numbuff;
                    break;
                case '=':
                    scores[i]=numbuff;
                    break;
                default:
                    std::cout<<"действие неверно\n";
                    flag = false;
                    break;
}
        if(flag){
            std::cout<<namebuff<<" score is now "<<scores[i]<<std::endl;
        }
        }
        std::cin>>namebuff>>chbuff>>numbuff;
    }
    std::cout<<"\n\n";
    print_all(names,scores, is_deleated);


    return 0;
}