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
    // linkedlist(int data){
    //     head = new node(data);
    //     head->data = data;
    // }

    void push_front(int data){
        node* x = new node(data);
        // cout<<x->data<<endl;
        x->data = data; //ชี้เพื่อที่จะให้ x เป็น head
        x->next = head; //เอาตัวที่เพิ่มเข้ามาใหม่ ชี้ไปที่ที่ head ชี้อยู่
        head = x;       // ย้าย head ชี้ที่ data ตัวแรก
    }

    int pop_front(){
        node* x = head;
        head = head->next;

        return x->data;
    }


    void print(){
        node* ptr = head; 
        while(ptr!=NULL){
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
            // cout<<"remain 1"<<endl;
            return -1;
        }
        if(search(pos) == -1){
            // cout<<"not found"<<endl;
            return -1;
        }
        
        for(int i = 0; i< position-1; i++){
            ptr = ptr->next;
        }
        
        if(head->data == pos){
            x = head;
            head = head->next;
            print();
            return x->data;
        }

        x = ptr->next;
        ptr->next = ptr->next->next;
        print();
        return x->data;
    }

    int search(int pos){
        node* ptr = head;
        int i = 0;
        while(ptr!=NULL){
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

    void insertbefore(int data, int pos){
        node*x = new node(data);
        node* ptr = head;
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
        
        while(ptr->next != NULL){
            if(ptr->next->data == pos){
                x->next = ptr->next;
                ptr->next = x;
                print();
                return;

            }
            ptr = ptr->next;
        }
        
        x->next = ptr->next;
        ptr->next = x;
        print();
        
       
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
            while(ptr->next != NULL){ //ใส่ท้ายสุด
                ptr = ptr->next;
            }
            x->next = ptr->next;
            ptr->next = x;
            print();
            return;
        }
        
        for(int i = 0; i< position; i++){
            ptr = ptr->next;
        }
        x->next = ptr->next;
        ptr->next = x;
        print();
        
        
    }
};

int main(){
    linkedlist* list = new linkedlist();

    // list->push_front(3);
    // list->push_front(2);
    // list->push_front(1);
    // cout<<list->head->data;
    // cout<<list->search(1);
    // list->insertbefore(3, 2);
    char mode;
    while(1){
        cin>>mode;
        if(mode == 'I'){
            int data, pos;
            cin>>data;
            cin>>pos;
            list->insertbefore(data, pos);
            // list->print();
            
        }
        else if(mode == 'A'){
            int data, pos;
            cin>>data;
            cin>>pos;
            list->insertafter(data, pos);
        }
        else if(mode == 'D'){
            int data;
            cin>>data;
            // cout<<list->erase(data);
            list->erase(data);
        }
        else if(mode == 'E'){
            break;
        }
    }
}