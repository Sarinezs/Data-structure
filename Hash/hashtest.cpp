#include<bits/stdc++.h>
#define size 17
using namespace std;
class node{
public:
    int key;
    string data;
    node* next;
    
    node(){
        key = -1;
        data = "-";
        next = NULL;
    }
};

class separate{
public:
    node* n[size];
    separate(){
        for(int i = 0; i<size; i++){
            n[i] = new node();
        }
    }

    void add(int keyin, string din){
        int k = keyin % size;
        if(n[k]->key == -1){
            n[k]->data = din;
            n[k]->key = keyin;
            n[k]->next = new node();
        }
        else{
            node* ptr = n[k];
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->data = din;
            ptr->key = keyin;
        }
    }

    string search(int keyin){
        int k = keyin % size;
        node* ptr = n[k];
        while(ptr != NULL){
            if(ptr->key == keyin){
                return ptr->data;
            }
            ptr = ptr->next;
        }
        return "-";
    }

    void print(){
        for(int i = 0; i<size; i++){
            node* ptr = n[i];
            while(ptr != NULL){
                cout<<ptr->key<<","<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    separate* s = new separate();
    char mode;
    int key;
    string data;
    while(1){
        cin>>mode;
        if(mode == 'a'){
            cin>>key;
            cin>>data;
            s->add(key,data);
        }
        else if(mode == 's'){
            cin>>key;
            cout<<s->search(key)<<endl;
        }
        else if(mode == 'p'){
            s->print();
        }
        else if(mode == 'e'){
            break;
        }
    }
}