#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next = NULL;

    node(int data){
        this->data = data;
    }
};
class linkedlist{
public:
    node* head;

    void push_front(int data){
        node* x = new node(data);
        x->next = head;
        head = x;
    }

    int pop_front(){
        node* x;
        x = head;
        head = head->next;

        return x->data;
    }

    int search(int pos){
        node* ptr = head;
        int i = 0;
        while(ptr != NULL){
            if(ptr->data == pos){
                return i;
            }
            else{
                i++;
                ptr = ptr->next;
            }
        }

        return -1;
    }

    void print(){
        node* ptr = head;
        while(ptr != NULL){
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
};

int main(){
    linkedlist* list = new linkedlist();

    list->push_front(4);
    list->push_front(3);
    list->push_front(2);
    list->push_front(1);

    cout<<list->pop_front()<<endl;
    cout<<list->pop_front()<<endl;
    cout<<list->pop_front()<<endl;
    cout<<list->pop_front()<<endl;
}