#include<iostream>
using namespace std;
class stack{
public:
    char a[20];
    int top = -1;
    void push(char y){
        a[++top] = y;
    }
    char pop(){
        return a[top--];
    }
    bool isbalance(string y){
        int n = y.length();
        for(int i = 0; i<n; i++){
            if(y[i] == '('){
                push(y[i]);
            }
            if(y[i] == ')'){
                if(top != -1){
                    pop();
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    bool isempty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    stack s;
    string y;
    cin>>y;
    
    bool check = (s.isbalance(y) && (s.isempty()));
    if(check == true)
        cout<<"Pass";
    else{
        cout<<"Error";
    }
}