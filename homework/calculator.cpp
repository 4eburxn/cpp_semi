#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    cout<<"введите ывражение (разрешены + и -): ";
    int lval, rval, res;
    char op;
    cin >> lval>>op>>rval;
    if (op == '+'){
        res = lval+rval;
    }
    else{
        res = lval-rval;
    }
    cout<<"результат: "<<res<<endl;
    return 0;
}

