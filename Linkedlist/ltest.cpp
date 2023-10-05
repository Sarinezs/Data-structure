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
            print();
            return;
        }
        if(position == -1){
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            x->next = ptr->next;
            ptr->next = x;
            print();
            return;
        }
        for(int i = 0; i<position; i++){
            ptr = ptr->next;
        }
        x->next = ptr->next;
        ptr->next = x;
        print();
        return;
    }

    void insertbefore(int data, int pos){
        node* x = new node(data);
        node* ptr = head;
        int position = search(pos);

        if(search(data) != -1){
            return;
        }
        if(head == NULL || head->data == pos){
            x->data = data;
            x->next = head;
            head = x;
            print();
            return;
        }
        if(position == -1){
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            x->next = ptr->next;
            ptr->next = x;
            print();
            return;
        }
        for(int i = 0; i<position-1; i++){
            ptr = ptr->next;
        }
        x->next = ptr->next;
        ptr->next = x;
        print();
        return;
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
            print();
            return x->data;
        }
        for(int i = 0; i<position-1; i++){
            ptr = ptr->next;
        }
        x = ptr->next;
        ptr->next = ptr->next->next;
        print();
        return x->data;

    }
};

int main(){
    linkedlist* list = new linkedlist();
    char mode;
    int data, pos;
    while(1){
        cin>>mode;
        if(mode == 'E'){
            break;
        }
        else if(mode == 'A'){
            cin>>data;
            cin>>pos;
            list->insertafter(data, pos);
        }
         else if(mode == 'I'){
            cin>>data;
            cin>>pos;
            list->insertbefore(data, pos);
        }
         else if(mode == 'D'){
            cin>>pos;
            list->erase(pos);
        }
    }
}