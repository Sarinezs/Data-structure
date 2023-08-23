#include <iostream>
using namespace std;

class Node {
public:
	
    int data;
    Node* next;
    Node* prev;


    Node(int dataValue) : data(dataValue), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
	
	
    void insertBefore(int newData, int searchData) {
    Node* x = new Node(newData);
    if (search(newData) != -1) {
        return;
    }
    if (head == NULL || head->data == searchData) {
        x->next = head;
        head = x;
        print();
        return;
    }

    Node* current = head;
    while (current->next != NULL) {
        if (current->next->data == searchData) {
            x->next = current->next;
            current->next = x;
            print();
            return;
        }
        current = current->next;
    }
    
    // If searchData was not found, insert at the end
    current->next = x;
    print();
	}
	
	
	
	void insertAfter(int newData, int searchData) {
    Node* x = new Node(newData);
    Node* ptr = head;
    int position = search(searchData);
    if (search(newData) != -1) {
        return;
    }
    if (position == -1) {
        // If searchData is not found, insert at the end
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = x;
        print();
        return;
    }
    
    for (int i = 0; i < position; i++) {
        ptr = ptr->next;
    }
    x->next = ptr->next;
    ptr->next = x;
    print();
	}

    


	
    int search(int searchData){
			Node* ptr = head;
			int i=0;
			while(ptr!=NULL){
				if(ptr->data == searchData){
					return i;
				}
				else{
					ptr = ptr->next;
					i++;
				}
			}
			return -1;
		}
//    int erase(int searchData){
//		Node* x;
//		Node* ptr = head;
//		int position = search(searchData);
//		for(int i=0;i<position-1;i++){
//			ptr = ptr->next;
//		}
//		x = ptr->next;
//		ptr->next = ptr->next->next;
//		
//		return x->data;
//		}
		
		
	int erase(int data) {
        if (head == NULL) {
            return -1;  // Return -1 if the list is empty
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            int removedData = temp->data;
            delete temp;
            return removedData;
        }

        Node* current = head;
        while (current->next != NULL) {
            if (current->next->data == data) {
                Node* temp = current->next;
                current->next = temp->next;
                int removedData = temp->data;
                delete temp;
                return removedData;
            }
            current = current->next;
        }

        return -1;  // Return -1 if the data was not found
    }
    

    void print() {
    Node* current = head;
    while (current != NULL) {
        if (current->data != 0) {
            cout << current->data << " ";
        }
        current = current->next;
    }
    cout << endl;
	}
};

int main() {
    LinkedList list;
	list.insertAtBeginning(0);
    int searchData,newData;
    char option;
	while(1){
		cin>>option;
		if(option=='A'){
			cin>>newData;
			cin>>searchData;
			list.insertAfter(newData,searchData);
//			list.print();
			
		}
		else if(option=='I'){
			cin>>newData;
			cin>>searchData;
			list.insertBefore(newData,searchData);
//			list.print();
		}
		else if(option=='D'){
			cin>>newData;
			list.erase(newData);
			list.print();
		}
		else if(option=='E'){
			break;
		}
	}
	
	
	
    return 0;
}

