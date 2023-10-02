#include<iostream>
#include<string>
#include<vector>
#include <stdlib.h>

void clear() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

bool ask_y_n(std::string question){ // return true if y
    std::string y_n;
    clear();
    while(true){
        std::cout << question;
        std::cin >> y_n;
        if(y_n == "y" || y_n == "Y"){
            return true;
        }
        else if(y_n == "n" || y_n == "N"){
            return false;
        }
        else{
            std::cout <<y_n<< "\n\nincorrect input\n";
        }
        
    }
}

void print_cur_state(std::vector<int>& a){
    int b = 0;
    if(a.size() == 0){
        std::cout<<"---the playground is empty---" <<std::endl;
    }
    for(auto& i:a){
        std::cout<<++b<<"("<<i<<")"<<"\t";
        for(int j = i; j>0;j--){
            std::cout<<"◉";
        }
        std::cout << "\n";
    }
}

int current_sum(std::vector<int> const& a){
    int rt=0;
    for(auto& i:a){
        rt=rt^i;
    }
    return rt;
}

int int_from_string(std::string s){
    int k = 1, return_value=0;
    for(auto i:s){
        return_value+=i*k;
        k=k*k+1;
    }
    return return_value;
}

void change_rows(std::vector<int>& game_start_state, int num_of_row, std::string operation){
    int amount;
    std::cin >> amount;
    switch (int_from_string(operation))
    {
    case '+':
        game_start_state[num_of_row-1]+=amount;
        break;
    case '-':
        game_start_state[num_of_row-1]-=amount;
        break;
    case '=':
        game_start_state[num_of_row-1]=amount;
        break;
    default:
        std::cin.setstate(std::ios_base::failbit);
        break;
    }
    if(game_start_state[num_of_row-1]<0){
        game_start_state[num_of_row-1] = 0;
        std::cin.setstate(std::ios_base::failbit);
    }
}

void std_cin_failure_clear(){
    
    if(!std::cin){ //something wrong with input
                clear();
                std::cout<<"incorrect input\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
}

void init_game(std::vector<int>& game_start_state, bool is_default_game){
    if(is_default_game){
        game_start_state = std::vector<int>{2,8,13};
        return;
    }
    else{
        int num_of_row, amount;
        if(!std::cin){std::cout<<"sdf";std::cin.ignore(1);}
        std::string operation,
                    message = "use num_of_row<0 to exit\n"\
                          "'<num_of_row> [+/-/=] <amount>' or '0 add' to add row\n";
        clear();
        while(true){
            clear();
            std_cin_failure_clear();
            
            std::cout<<"the current state of the game:\n";
            print_cur_state(game_start_state);
            std::cout<< "\n" << message;
            
            std::cin >> num_of_row;
            if(!std::cin){continue;}

            if(num_of_row<0 && ask_y_n("do you want to exit edit mode?\n[y/n]")){ // exit mode
                if(game_start_state.size() == 0 && ask_y_n("the playground is empty. \
                                                            use default values?\n[y/n]")){
                    init_game(game_start_state,true);
                    return;
                }
                return;
            }
            if(num_of_row<0){
                continue;
            }

            std::cin >> operation;
            
            if(num_of_row == 0 && operation == "add"){
                game_start_state.push_back(0);
            }
            else if(num_of_row == 0 || operation == "add" || num_of_row > game_start_state.size())
                {std::cin.setstate(std::ios_base::failbit);continue;}
            else{change_rows(game_start_state,num_of_row,operation);}
        }
    }
}




void response_move(std::vector<int>& game_state, int& cur_move){
    bool flag = true;
    std::cout << "My turn\nnum_of_row   N\n";
    int l = current_sum(game_state);
    
    if(l >0 ){
        for(size_t i =0;i<game_state.size();i++){
            if((game_state[i]^l) < game_state[i]){
                std::cout<<i+1 <<"\t     " << (game_state[i]-(game_state[i]^l)) <<"\n";
                game_state[i]=(game_state[i]^l);
                std::cout<<"\n\n";
                flag = false;
                break;
            }
        }
    }
    if(flag){
        for(size_t i = 0; i<game_state.size();i++){
            if(game_state[i]>0){
                std::cout<<i+1 <<"\t" << 1<<"\n";
                game_state[i]-=1;
                break;
            }
        }
    }
    cur_move+=1;

}

void men_move(std::vector<int>& game_state, int& cur_move){
    int a,b;
    std_cin_failure_clear();
    
    std::cout << "the current state of the game:\n";
    print_cur_state(game_state);
    std::cout << "Your turn\n"
              << "num_of_row   N\n";
    std::cin >> a >> b;
    if(game_state[a-1]<b || a<0 || a>game_state.size() || b<0){
        std::cin.setstate(std::ios_base::failbit);
    }
    else{
        game_state[a-1]-=b;
        cur_move+=1;
    }
}

bool is_game_end(std::vector<int>& game_state, int cur_move){
    int sum_of_rows=0;
    for(auto i:game_state){
        sum_of_rows+=i;
    }
    if(sum_of_rows == 0){
        if(cur_move%2){
            std::cout<<"you loose!"<<std::endl;
        }
        else{
            std::cout<<"you win!"<<std::endl;
        }
        return true;
    }
    return false;
}

int main(){
    std::vector<int> game_state;
    int cur_move;
    
    bool flag = false;
    clear();
    if(ask_y_n("will you play first?\n[y/n]:")){    // who makes first move
        cur_move = 1; // human
    }
    else{
        cur_move = 0; // program 
    }
    
    if(ask_y_n("Do you want to customise the game?\n[y/n]:")){    // change game start state
        init_game(game_state, false);
    }
    else{
        init_game(game_state, true);
    }
    clear();
    if(cur_move==0){
        std::cout << "the start state of the game:\n";
        print_cur_state(game_state);
        std::cout<<std::endl;
    }
    
    while(!is_game_end(game_state, cur_move)){
        if(cur_move%2 == 1){
            men_move(game_state, cur_move);
        }
        else{
            response_move(game_state, cur_move);
        }
        if(cur_move%2==0 && cur_move>1){clear();} 
    }

    return 0;
}
