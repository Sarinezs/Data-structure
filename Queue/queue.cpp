#include<iostream>
using namespace std;
class queue{
public:
    int a[10];
    int head = 0;
    int tail = -1;
    int queuesize = 0;

    void enqueue(int data){
        if(queuesize >= 9){
            cout<<"queue full"<<endl;
        }
        else if(tail > 9){
            tail = 0;
            queuesize++;
            a[tail] = data;
        }
        else{
            tail++;
            queuesize++;
            a[tail] = data;
        }
    }

    int dequeue(){
        if(queuesize <= 0){
            cout<<"queue empty"<<endl;
            return -1;
        }
        else if(head >= 9){
            int x = a[head];
            head = 0;
            queuesize--;
            return x;
        }
        else{
            int x = a[head];
            head++;
            queuesize--;
            return x;
        }
    }

    void print(){
        if(queuesize > 0){
            int ptr1 = head;
            for(int i = 0; i<queuesize; i++){
                cout<<a[ptr1]<<" ";
                ptr1 = (ptr1 + 1) % 10;
            }
            cout<<endl;
        }
        
    }
};

int main(){
    queue q;
    char mode;
    while(1){
        cin>>mode;
        if(mode == 'e'){
            int data;
            cin>>data;
            q.enqueue(data);
        }
        else if(mode =='d'){
            cout<<q.dequeue()<<endl;
        }
        else if(mode == 'p'){
            q.print();
        }
        else if(mode == 'n'){
            cout<<q.queuesize<<endl;
        }
        else if(mode == 's'){
            if(q.queuesize > 0){
                cout<<q.a[q.head]<<" "<<q.a[q.tail]<<endl;
            }
        }
        else if(mode == 'x'){
            break;
        }
    }
}