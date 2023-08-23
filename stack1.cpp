#include<iostream>
using namespace std;
class stack{
public:
    char arr[20];
    char arr1[20];
    int top = -1;

    void push(char data){
        arr[++top] = data;
    }

    char pop(){   
        return arr[top--];
    }

    int isBalanced(string y){
        int n = y.length();
        for(int i = 0 ; i < n ;i++){
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

    int isEmpty(){
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
   
    int check = s.isBalanced(y) && s.isEmpty();
    if(check == 1){
        cout<<"Pass";
    }
    else if(check == 0){
        cout<<"Error";
    }
}