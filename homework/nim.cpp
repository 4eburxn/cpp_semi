#include<iostream>
#include<set>
#include<vector>

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
    std::vector<int> gm;
    char y_n; 
    int N = -1,a,b;
    init_game(gm, true);
    bool flag = false;
    clear();
    std::cout<<"welcome to the nim game"<<std::endl;
    std::cout << "will you play first?\n[y/n]:";
    while(N==-1){
        std::cin >> y_n;
        if(y_n == 'y' || y_n == 'Y'){
            N = 1;
        }
        else if(y_n == 'n' || y_n == 'N'){
            N=0;
        }
        else{
            std::cout << "samesing vrong vith inpoot\nwill you play first?\n[y/n]:";
        }
    }
    clear();
    while(gm.size() != 0){
        
        if(N%2 == 1){
            if(flag){
                clear();
                std::cout<<"самсынг вронг\n";
            }
            std::cout << "\nthe current state of the game:\n";
            print_cur_state(gm);
            std::cout << "Your turn\nnum_of_row   N\n";
            std::cin >> a>>b;
            if(gm[a-1]<b || a<0 || a>gm.size() || b<0){
                flag = true;
            }
            else{
                gm[a-1]-=b;
                N+=1;
                flag = false;
            }
        }
        else{
            flag = true;
            std::cout << "My turn\nnum_of_row   N\n";
            int l = current_sum(gm);
            
            if(l >0 ){for(size_t i =0;i<gm.size();i++){
                if(gm[i]^l < gm[i]){
                    std::cout<<i+1 <<"\t     " << (gm[i]-gm[i]^l) <<"\n";
                    gm[i]=gm[i]^l;
                    std::cout<<current_sum(gm)<<"\n\n";
                    flag = false;
                    break;
                }
            }}
            if(flag){
                for(size_t i = 0; i<gm.size();i++){
                    if(gm[i]>0){
                        std::cout<<i+1 <<"\t" << 1<<"\n";
                        gm[i]-=1;
                        break;
                    }
                }
            }
            N+=1;
        }
        if(N%2==0){clear();}

        b = 0;
        for(auto i:gm){
            b+=i;
        }
        if(b == 0){
            if(N%2){
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
