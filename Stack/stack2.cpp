#include<stdio.h>
#include<iostream>

using namespace std;

class stack{
public:	
	char arr[100];
	int top = -1;
	void push(char item);
	char pop();
	
};

char stack::pop(){
	
	if(top<=-1){
		cout<<"no item";
	}
	return arr[top--];
}

void stack::push(char item){
	
	top++;
	arr[top]=item;
}

int main(){
	
	stack s1;
	string text; 
	cin>>text;
	
	for(int i=0;i<text.length();i++){
		s1.push(text[i]);
	}
	
	for(int i=0;i<text.length();i++){
		cout<<s1.pop();
	}
	
	
	return 0;
}

