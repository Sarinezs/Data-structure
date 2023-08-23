#include<iostream>
using namespace std;
class stack{
public:
    int a[20];
    int top = -1;

    void push(int data){
        a[++top] = data;
    }

    int pop(){


        return a[top--];
    }

    void print(){
        if(top != -1){
            for(int i = 0; i<top+1; i++){
            cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    stack s;
    char mode;
    while(1){
        cin>>mode;
        if(mode == 'U'){
            int data;
            cin>>data;
            s.push(data);
        }
        else if(mode == 'O'){
            if(s.top != -1){
                cout<<s.pop()<<endl;
            }
        }
        else if(mode == 'T'){
            if(s.top != -1){
                cout<<s.a[s.top]<<endl;
            }
        }
        else if(mode == 'P'){
            s.print();
        }
        else if(mode == 'N'){
            if(s.top != -1){
                cout<<s.top +1 <<endl;
            }
            else{
                cout<<0<<endl;
            }

        }
        else if(mode == 'X'){
            break;
        }
    }
}