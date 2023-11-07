#include<iostream>
using namespace std;
#define size 17
class node{
public:
    int key;
    string value;
    node* next;

    node(){
        key = -1;
        value = "";
        next = NULL;
    }

    node(int keyin, string data){
        key = keyin;
        value = data;
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

    void add(int keyin, string data){
        int k = keyin % size;
        if(n[k]->key == -1){
            n[k]->key = keyin;
            n[k]->value = data;
            // n[k]->next = new node();
        }
        else{
            node* x = new node(keyin, data);
            node* ptr = n[k];
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = x;
        }
    }

    string search(int keyin){
        int k = keyin % size;
        node* ptr = n[k];
        while(ptr != NULL){
            if(ptr->key == keyin){
                return ptr->value;
            }
            ptr = ptr->next;
        }            
        return "-";
    }

    void print(){
        for(int i = 0; i<size; i++){
            node* ptr = n[i];
            while(ptr != NULL){
                cout<<ptr->key<<","<<ptr->value<<" ";
                ptr = ptr->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    separate* s = new separate();;
    char mode;
    int key;
    string data;
    while(1){
        cin>>mode;
        if(mode == 'a'){
            cin>>key;
            cin>>data;
            s->add(key, data);
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