#include<bits/stdc++.h>
using namespace std;
class heap{
public:
    int q[1000];

    heap(){
        q[0] = 0;
    }

    void heapify(){ // ทำเป็น heap
        int j = q[0];
        if(j % 2 == 0){
            q[j+1] = -INT_MAX;
        }
        else{
            j = j -1;
        }
        while(j >= 1){
            int i = j;
            while(i <= q[0]){
                int p = i/2;
                int r = i+1;
                int l = i;
                if(q[l] >= q[r] && q[l] > q[p]){
                    int t = q[l];
                    q[l] = q[p];
                    q[p] = t;
                    i = 2*l;
                }
                else if(q[r] > q[l] && q[r] > q[p]){
                    int t = q[r];
                    q[r] = q[p];
                    q[p] = t;
                    i = 2*r;
                }
                else{
                    break;
                }
            }
            j = j - 2;
        }
    }

    void insert(int n){
        if(q[0] < 999){ // q[0] เก็บจำนวนข้อมูล
            q[0] = q[0] + 1; // ข้อมูลเพิ่มมา 1
            q[q[0]] = n; // เพิ่มข้อมูลต่อท้าย
            int i = q[0];
            while(i > 1 && q[i/2] < q[i]){ // ตัวที่เพิ่มเข้ามา มากกว่า parentไหม
                int t = q[i/2];
                q[i/2] = q[i];
                q[i] = t;
                i = i/2;
            }
        }
    }

    int delete_data(){
        if(q[0] > 0){
            int s = q[1]; // เก็บค่าไว้ที่ s 
            q[1] = q[q[0]]; // เอาตัวท้ายสุด มาแทนที่ ตัวแรกสุด
            q[0] = q[0] - 1; // จำนวนข้อมูลลดไป 1
            int p = 1; // p = parent | 1 = ชั้นที่ 1(ตัวบนสุด)
            while(p <= q[0]){ // loop เมื่อตัวท้ายไปแทนที่ตัวแรก จะ sortข้อมูล ใหม่เป็น max heap (ในcodeนี้ เป็น max heap)
                int l = p*2; // l = left
                int r = (p*2) + 1; // r = right
                if(l <= q[0] && q[l] > q[p] && q[l] >= q[r]){ // ซ้าย มากกว่า ตัวบน และ ซ้าย มากกว่าเท่ากับ ขวา
                   int t = q[l];
                   q[l] = q[p];
                   q[p] = t;
                   p = l; 
                }
                else if(r <= q[0] && q[r] > q[p] && q[r] > q[l]){ // ขวา มากกว่า ตัวบน และ ขวา มากกว่า ซ้าย
                    int t = q[r];
                    q[r] = q[p];
                    q[p] = t;
                    p = r;
                }
                else{
                    break;
                }
            }
            return s;
        }
        else{
            return NULL;
        }
    }

    void print(){
        for(int i = 1; i<=q[0]; i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    heap h;
    char mode;
    while(1){
        int data;
        cin>>mode;
        if(mode == 'a'){
            cin>>data;
            h.insert(data);
        }
        else if(mode == 'd'){
            int a = h.delete_data();
            if(a != NULL){
                cout<<a<<endl;
            }
            else{
                cout<<"Empty"<<endl;
            }
        }
        else if(mode == 'p'){
            // h.heapify();
            h.print();
        }
        else if(mode == 'e'){
            break;
        }
    }
}