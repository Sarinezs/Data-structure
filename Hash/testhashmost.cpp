#include<iostream>
#define size 17
using namespace std;
class node{
public:
    int key;
    string val;
    node* next;

    node(){
        key = -1;
        val = "-";
        next = NULL;
    }

    node(int kin, string d){
        key = kin;
        val = d;
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

    void add(int key, string data){
            int k = key % size;
            if(n[k]->key == -1){
                n[k]->key = key;
                n[k]->val = data;
                n[k]->next = NULL;
            } 
            else{
                node* x = new node(key , data);
                node* ptr = n[k];
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }
                ptr->next = x;
            }
    }

    string search(int key){
        int k = key % size;
        node* ptr = n[k];
        while(ptr != NULL){
            if(ptr->key == key){
                return ptr->val;
            }
            ptr = ptr->next;
        }
        return "-";
    }

    void print(){
        for(int i = 0; i<size; i++){
            node* ptr = n[i];
            while(ptr != NULL){
                cout<<ptr->key<<","<<ptr->val<<" ";
                ptr = ptr->next;
            }
            cout<<endl;
        }
    }
    
};

int main(){
    separate* h = new separate();
    char mode;
    int key;
    string data;
    while(1){
        cin>>mode;
        if(mode == 'a'){
            cin>>key;
            cin>>data;
            h->add(key, data);
        }
        else if(mode == 's'){
            cin>>key;
            cout<<h->search(key)<<endl;
        }
        else if(mode == 'p'){
            h->print();
        }
    }
}