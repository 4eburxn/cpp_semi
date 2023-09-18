#include<iostream>
#include<string>
#include<vector>

bool ask_y_n(){ // return bool if y
    std::cout << "will you play first?\n[y/n]:";
    std::string y_n;
    while(true){
        std::cin >> y_n;
        if(y_n == "y" || y_n == "Y"){
            return true;
        }
        else if(y_n == "n" || y_n == "N"){
            return false;
        }
        else{
            std::cout << "samesing vrong vith inpoot\nwill you play first?\n[y/n]:";
        }
    }
}

int current_sum(std::vector<int> const& a){
    int rt=0;
    for(auto& i:a){
        rt=rt^i;
    }
    return rt;
}

int init_game(std::vector<int>& a, bool default_game){
    if(default_game){
        a = std::vector<int>{2,8,13};
        return 0;
    }
    return 0;
}


void print_cur_state(std::vector<int>& a){
    int b = 0;
    for(auto& i:a){
        std::cout<<++b<<"\t";
        for(int j = i; j>0;j--){
            std::cout<<"◉";
        }
        std::cout << "\n";
    }
}
void clear() {
    std::cout << "\x1B[2J\x1B[H"; // only in *nix
}

int main(){
    std::vector<int> game_state;
    char y_n; 
    int cur_move ,a,b;
    init_game(game_state, true);
    bool flag = false;
    clear();
    std::cout<<"welcome to the nim game"<<std::endl;
    if(ask_y_n()){    // who makes first move
        cur_move = 1; // men
    }
    else{
        cur_move = 0; // program 
    }
    
    clear();
    while(game_state.size() != 0){
        
        if(cur_move%2 == 1){
            if(flag){
                clear();
                std::cout<<"самсынг вронг\n";
            }
            std::cout << "\nthe current state of the game:\n";
            print_cur_state(game_state);
            std::cout << "Your turn\nnum_of_row   N\n";
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
            
            if(l >0 ){for(size_t i =0;i<game_state.size();i++){
                if(game_state[i]^l < game_state[i]){
                    std::cout<<i+1 <<"\t     " << (game_state[i]-game_state[i]^l) <<"\n";
                    game_state[i]=game_state[i]^l;
                    std::cout<<current_sum(game_state)<<"\n\n";
                    flag = false;
                    break;
                }
            }}
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
                std::cout<<"YOU WIN!"<<std::endl;
            }
            else{
                std::cout<<"you loose!"<<std::endl;
            }
            break;
        }
        
    }

    return 0;
}
