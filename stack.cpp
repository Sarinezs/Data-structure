#include<iostream>
using namespace std;
class stack{
  public:
    int arr[20];
    int top = -1;

    void push(int item){
      arr[++top] = item;
    }

    int pop(){
      return arr[top--];
    }
};

int main(){
  stack s;
  cout<<"enter five value: "<<endl;
  for(int i = 0; i<5; i++){
    int a;
    cin>>a;
    s.push(a);
  }

  cout<<"pop's value: "<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  
  
  s.pop();
}