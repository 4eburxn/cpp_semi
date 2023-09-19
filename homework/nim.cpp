#include<iostream>
#include<string>
#include<vector>
#include <stdlib.h>

void clear() {
    std::cout << "\x1B[2J\x1B[H"; //  *nix
    system("cls");
}


bool ask_y_n(std::string question){ // return bool if y
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
            std::cout << "\n\nincorrect input\n";
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

void init_game(std::vector<int>& game_start_state, bool is_default_game){
    if(is_default_game){
        game_start_state = std::vector<int>{2,8,13};
        std::cout <<"\nthe start state of the game:\n";
        print_cur_state(game_start_state);
        return;
    }
    else{
        int num_of_row, amount;
        std::string operation;
        std::string msg = "use num_of_row<0 to exit\n"\
                          "'<num_of_row> [+/-/=] <amount>' or '0 add' to add row\n";
        
        while(true){
            clear();
            std::cout<<"the current state of the game:\n";
            print_cur_state(game_start_state);
            std::cout<< "\n" <<msg;
            
            std::cin >> num_of_row;

            if(num_of_row<0 && ask_y_n("do you want to exit edit mode?\n[y/n]")){ // exit mode
                if(game_start_state.size() == 0\
                   && ask_y_n("the playground is empty. use default values?\n[y/n]"))
                {
                    init_game(game_start_state,true);
                    return;
                }
                return;
            }

            std::cin >> operation;
            if(num_of_row == 0 && operation == "add"){
                game_start_state.push_back(0);
            }
            else if(num_of_row == 0 || operation == "add" || num_of_row > game_start_state.size())
                {std::cout<<"incorrect input\n";}
            else{ // change mode
                std::cin >> amount;
                if(num_of_row != 0 && operation == "+")
                    game_start_state[num_of_row-1]+=amount;
                else if(num_of_row != 0 && operation == "-")
                    game_start_state[num_of_row-1]-=amount;
                else if(num_of_row != 0 && operation == "=")
                    game_start_state[num_of_row-1]= amount;
                else{std::cout<<"incorrect input\n";}
            }

            
        }
    }
    return;
}





int main(){
    std::vector<int> game_state;
    char y_n; 
    int cur_move ,a,b;
    
    bool flag = false;
    clear();
    std::cout<<"welcome to the nim game"<<std::endl;
    
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
    while(game_state.size() != 0){
        
        if(cur_move%2 == 1){
            if(flag){
                clear();
                std::cout<<"incorrect input\n";
            }
            std::cout << "\nthe current state of the game:\n";
            print_cur_state(game_state);
            std::cout << "Your turn\n"
                      << "num_of_row   N\n";
            std::cin >> a>>b;
            if(game_state[a-1]<b || a<0 || a>game_state.size() || b<0){
                flag = true;
            }
            else{
                game_state[a-1]-=b;
                cur_move+=1;
                flag = false;
            }
        }
        else{
            flag = true;
            std::cout << "My turn\nnum_of_row   N\n";
            int l = current_sum(game_state);
            
            if(l >0 ){
                for(size_t i =0;i<game_state.size();i++){
                    if((game_state[i]^l) < game_state[i]){
                        std::cout<<i+1 <<"\t     " << (game_state[i]-(game_state[i]^l)) <<"\n";
                        game_state[i]=(game_state[i]^l);
                        std::cout<<current_sum(game_state)<<"\n\n";
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
        if(cur_move%2==0){clear();}

        b = 0;
        for(auto i:game_state){
            b+=i;
        }
        if(b == 0){
            if(cur_move%2){
                std::cout<<"you loose!"<<std::endl;
            }
            else{
                std::cout<<"you win!"<<std::endl;
            }
            break;
        }
        
    }

    return 0;
}
