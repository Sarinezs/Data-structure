#include<iostream>
using namespace std;
class open_addressing{
public:
	int hash_key[100];
	string hash_table[100];
	int n = 0;
	int r = 7;
	
	open_addressing(int p_n, int p_r){
		n = p_n;
		r = p_r;
		for(int i = 0; i < n; i++){
			hash_key[i] = -1;
			hash_table[i] = "-";
		}
	}
	
	void add_modulo_division(int key, string data){
		hash_key[key%n] = key;
		hash_table[key%n] = data;
	}
	
	string search_modulo_division(int key){
		if(key == hash_key[key%n]){
			return hash_table[key%n];
		}
		else{
			return "-";
		}
	}
	
	void add_linear_probing(int key, string data){
		for(int i = 0; i < n; i++){
			int j = (key + i)%n;
			if(hash_key[j] == -1){
				hash_key[j] = key;
				hash_table[j] = data;
				break;
			}
		}
	}
	
	string search_linear_probing(int key){
		for(int i = 0; i < n; i++){
			int j = (key+i)%n;
			if(hash_key[j] == key){
				return hash_table[j];
			}
			if(hash_key[j] == -1){
				return "-";
			}
		}
	}
	
	void add_quadratic_probing(int key, string data){
		for(int i = 0; i < n; i++){
			int j = (key+i*i)%n;
			if(hash_key[j] == -1){
				hash_key[j] = key;
				hash_table[j] = data;
				break;
			}
		}
	}
	
	string search_quadratic_probing(int key){
		for(int i = 0; i < n; i++){
			int j = (key+(i*i))%n;
			if(hash_key[j] == key){
				return hash_table[j];
			}
			if(hash_key[j] == -1){
				return "-";
			}
		}
	}
	
	void add_double_hashing(int key, string data){
		int hash2 = r - (key % r);
		for(int i = 0; i < n; i++){
			int j = (key + i*hash2)%n;
			if(hash_key[j] == -1){
				hash_key[j] = key;
				hash_table[j] = data;
				break;
			}
		}
	}
	
	string search_double_hashing(int key){
		int hash2 = r - (key%r);
		for(int i = 0; i< n; i++){
			int j = (key + (i*hash2))%n;
			if(hash_key[j] == key){
				return hash_table[j];
			}
			if(hash_key[j] == -1){
				return "-";
			}
		}
	}
	
	void print(){
		for(int i = 0; i< n ; i++){
			cout<<"("<<hash_key[i]<<","<<hash_table[i]<<")";
		}
		cout<<endl;
	}
};

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
	node(string s, int k){
		key = k;
		data = s;
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
	
	void add(int key , string data){
		int j = key%n;
		if(hash_table[j].next == NULL){
			hash_table[j].data = data;
			hash_table[j].key = key;
			hash_table[j].next = new node();
		}
		else{
			node* t_node = hash_table[j].next;
			while(t_node->next != NULL){
				t_node = t_node->next;
			}
			t_node->data = data;
			t_node->key = key;
			t_node->next = new node();
		}
	}
	
	string search(int key){
		int j = key%n;
		if(hash_table[j].key == key){
			return hash_table[j].data;
		}
		else{
			node* t_node = hash_table[j].next;
			while(t_node != NULL){
				if(key == t_node->key){
					return t_node->data;
				}
				t_node = t_node->next;
			}
		}
		return "-";
	}
	
	void print(){
		for(int i =0; i<n; i++){
			cout<<"("<<hash_table[i].key<<","<<hash_table[i].data<<")"<< " ";
			if(hash_table[i].next != NULL){
				node* t_node = hash_table[i].next;
				while(t_node->next != NULL){
					cout<<"("<<t_node->key<<","<<t_node->data<<")"<< " ";
					t_node = t_node->next;
				}
			}
			cout<<endl;
		}
		cout<<endl;
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
