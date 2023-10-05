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

    int search(int pos){
        node* ptr = head;
        int i = 0;
        while(ptr != NULL){
            if(ptr->data == pos){
                return i;
            }
            else{
                ptr = ptr->next;
                i++;
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

    int erase(int pos){
        node* x;
        node* ptr = head;
        int position = search(pos);
        if(head == NULL){
            return -1;
        }
        if(head->next == NULL){
            return -1;
        }
        if(search(pos) == -1){
            return -1;
        }
        if(head->data == pos){
            x = head;
            head = head->next;
            return x->data;
        }
        for(int i = 0; i<position-1; i++){
            ptr = ptr->next;
        }
        x = ptr->next;
        ptr->next = ptr->next->next;
    }

    void insertafter(int data, int pos){
        node* x = new node(data);
        node* ptr = head;
        int position = search(pos);
        if(search(data) != -1){
            return;
        }
        if(head == NULL){
            x->data = data;
            x->next = head;
            head = x;
            return;
        }
        if(position == -1){
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            x->next = ptr->next;
            ptr->next = x;
        }
        for(int i = 0; i<position; i++){
            ptr = ptr->next;
        }
        x->next = ptr->next;
        ptr->next = x;
        return;
    }
};