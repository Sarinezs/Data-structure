#include<iostream>
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
class separate_chaining{
public:
    int n;
    node hash_table[100];
    separate_chaining(int p_n){
        n = p_n;
    }

    void add(int key, string data){
        int j = key%n;
        if(hash_table[j].next == NULL){
            hash_table[j].data = data;
            hash_table[j].key = key;
            hash_table[j].next = new node();
        }
        else{
            node* tnode = hash_table[j].next;
            while(tnode->next != NULL){
                tnode = tnode->next;
            }
            tnode->data = data;
            tnode->key = key;
            tnode->next = new node();
        }
    }

    string search(int key){
        int j = key%n;
        for(int i = 0; i<n; i++){
            if(hash_table[j].key == key){
                return hash_table[j].data;
            }
            else{
                node* tnode = hash_table[j].next;
                while(tnode != NULL){
                    if(tnode->key == key){
                        return tnode->data;
                    }
                    tnode = tnode->next;
                }
            }
            return "-";
        }
    }

    void print(){
        for(int i = 0; i<n; i++){
            cout<<"("<<hash_table[i].key<<","<<hash_table[i].data<<")";
            if(hash_table[i].next != NULL){
                node* tnode = hash_table[i].next;
                while(tnode->next != NULL){
                    cout<<"("<<tnode->key<<","<<tnode->data<<")";
                    tnode = tnode->next;
                }
            }
            cout<<endl;
        }
    }
};

int main(){
	separate_chaining s(17);
	char mode;
	int key;
	string data;
	while(1){
		cin>>mode;
		if(mode == 'a'){
			cin>>key;
			cin>>data;
			s.add(key, data);
		}
		else if(mode == 'p'){
			s.print();
		}
		else if(mode == 's'){
			cin>>key;
			cout<<s.search(key)<<endl;
		}
		else if(mode == 'e'){
			break;
		}
	}
}