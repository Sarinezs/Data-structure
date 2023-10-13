#include<iostream>
using namespace std;
class open_addressing{
public:
	int hash_key[100];
	string hash_table[100];
	int n = 0;
	int r = 0;
	
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
			// if(hash_key[j] == -1){
			// 	return "-";
			// }
			else{
				return "-";
			}
		}
	}
	
	void print(){
		for(int i = 0; i< n ; i++){
			cout<<"("<<hash_key[i]<<","<<hash_table[i]<<")";
            cout<<endl;
		}
	}
};

int main(){
	open_addressing s(17, 11);
	char mode;
	int key;
	string data;
	while(1){
		cin>>mode;
		if(mode == 'a'){
			cin>>key;
			cin>>data;
			s.add_double_hashing(key, data);
		}
		else if(mode == 'p'){
			s.print();
		}
		else if(mode == 's'){
			cin>>key;
			cout<<s.search_double_hashing(key)<<endl;
		}
		else if(mode == 'e'){
			break;
		}
	}
}
