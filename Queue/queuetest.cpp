#include<iostream>
using namespace std;
class queue{
public:
    int n;
    int a[3];
    int head = 0;
    int tail = -1;
    int queuesize = 0;

    queue(int size){
        n = size;
        a[n];
    }

    void enqueue(int data){
        if(queuesize >= n){
            cout<<"full";
        }
        else if(tail >= n-1){
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
            cout<<"empty";
            return -1;
        }
        else if(head >= n-1){
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
            int ptr = head;
            for(int i = 0; i<queuesize; i++){
                cout<<a[ptr]<<" ";
                ptr = (ptr + 1) % n;
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cin>>n;
    queue q = queue(n);
    char mode;
    int data;
    while(1){
        cin>>mode;
        if(mode == 'x'){
            break;
        }
        else if(mode == 'd'){
            cout<<q.dequeue();
        }
        else if(mode == 'e'){
            cin>>data;
            q.enqueue(data);
        }
        else if(mode == 'n'){
            cout<<q.queuesize<<endl;
        }
        else if(mode == 'p'){
            q.print();
        }
    }
}