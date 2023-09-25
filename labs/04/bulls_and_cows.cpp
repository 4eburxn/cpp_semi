#include<iostream>
#include<vector>

int count(const std::vector<char>& digits, char d){
    int k = 0;
    for(size_t i =0 ;i<digits.size();i++){
        if(digits[i] == d){
            ++k;
        }
    }
    return k;
}

void validate(const std::vector<char>& number){
    for(size_t i = 0; i<number.size();i++){
        if (number[i] < '0' || number[i]>'9'){
            throw std::runtime_error("the number contains not digits");
        }
        if(count(number, number[i]) != 1){
            throw std::runtime_error("Digits of number is not unique");
        }

    }
}


std::vector<char> user_guess(){
    std::vector<char> number(4);
    for(size_t i = 0;i<number.size();i++)
    {
        std::cin >> number[i];
    }
    if(!std::cin){
        throw std::runtime_error("ivalid input");
    }
    validate(number);
    return number;
}

int main()
try{
    std::cout<<"bulls and cows game.\n"
             <<"Computer sets a number of 4 unique digits\n"
             <<"bull means right digits on the right position\n\n"
             << "game is on" << std::endl;

    std::vector<char> number{'1','3','7','2'};

    int bulls,cows;
    do
    {
        bulls =cows = 0;
        std::vector<char> ugess = user_guess();

        for(size_t i = 0; i < ugess.size();i++){
            if(ugess[i] == number[i]){
                bulls++;
            }
            else if(count(ugess,number[i]) == 1){
                cows++;
            }
        }
        std::cout<<"bulls:"<<bulls
                 <<"\ncows"<<cows<<std::endl;
    } while (bulls !=4);
    std::cout<<"game is over"<<std::endl;
    return 0;
}
catch(std::exception& e){
    std::cerr<<e.what()<<std::endl;
    return 1;
}
catch(...){
    std::cerr<<"Unkown error"<<std::endl;
    return 2;
}