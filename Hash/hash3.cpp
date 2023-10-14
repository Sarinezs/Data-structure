#include<iostream>
#define n 5
#define n_student 7
using namespace std;
class Node_Subject{
public:
    int subject_key;
    string subject_name;
    Node_Subject* subject_next;
    Node_Subject(){
        subject_key = -1;
        subject_name = "-";
        subject_next = NULL;
    }
};
class Node_Student{
public:
    string student_key;
    string student_surname;
    string student_lastname;
    string student_score;
    Node_Student* student_next;
    Node_Student(){
        student_key =  "-";
        student_surname =  "-";
        student_lastname =  "-";
        student_score =  "-";
        student_next = NULL;
    }
    Node_Student(string key, string s_name, string l_name, string mark){
        student_key = key;
        student_surname = s_name;
        student_lastname = l_name;
        student_score = mark;
        student_next = NULL;
    }
};

class separate{
public:
    Node_Subject* subject_node[n];
    Node_Student* student_node[n_student];
    separate(){
        for(int i = 0; i<n; i++){
            subject_node[i] = new Node_Subject();
        }
        for(int i = 0; i<n_student; i++){
            student_node[i] = new Node_Student();
        }
    }

    void add_subject(int s_key, string subject){
        for(int i = 0; i<n; i++){
            int k = (s_key + i) % n;
            if(subject_node[k]->subject_key == -1) {
                subject_node[k]->subject_key = s_key;
                subject_node[k]->subject_name = subject;
                break;
            }
            if(subject_node[k]->subject_key == s_key){
                cout<<"already has this subject"<<endl;
                break;
            }

        }
    }

    string search_subject(int key){
        for(int i = 0; i<n; i++){
            int k = (key + i) % n;
            if(subject_node[k]->subject_key == key){
                return subject_node[k]->subject_name;
            }
            if(subject_node[k]->subject_key == -1){
                return "-";
            }
        }        
    }

    void add_student(int sub_key, string stu_key, string s_name, string l_name, string mark){
        string status = search_subject(sub_key);
        if(status == "-"){
            cout<<"don't have this subject"<<endl;
        }
        else{
            int k = sub_key % n_student;
            if(student_node[k]->student_key == "-"){
                student_node[k]->student_key = stu_key;
                student_node[k]->student_surname = s_name;
                student_node[k]->student_lastname = l_name;
                student_node[k]->student_score = mark;
            }
            else{
                Node_Student* student = new Node_Student(stu_key, s_name, l_name, mark);
                Node_Student* ptr = student_node[k];
                while(ptr->student_next != NULL){
                    ptr = ptr->student_next;
                }
                ptr->student_next = student;
            }
        }
    }

    void print_subject(){
        cout<<"This is subject"<<endl;
        for(int i = 0; i<n; i++){
            cout<<subject_node[i]->subject_key<<","<<subject_node[i]->subject_name<<endl;
        }
    }

    void print_student(int key){
        string status = search_subject(key);
        if(status == "-"){
            cout<<"don't have this subject"<<endl;
        }
        else{
            cout<<"this is "<<status<<" score :"<<endl;
            int k = key % n_student;
            Node_Student* ptr = student_node[k];
            while(ptr != NULL){
                cout<<ptr->student_key<<" "<<ptr->student_surname<<" "<<ptr->student_lastname<<" "<<ptr->student_score<<endl;
                ptr = ptr->student_next;
            }
        }
        
    }
};

int main(){
    char mode;
    int sub_key;
    string sub_name;
    string stu_key;
    string stu_surname;
    string stu_lastname;
    string stu_score;
    separate* s = new separate();

    cout<<"How to use :"<<endl;
    cout<<"a = add_subject (ex):---> a 189 SA"<<endl;
    cout<<"i = add_student (ex):---> i 189 332 suriya meerua 50"<<endl;
    cout<<"u = print_student (ex):---> u 189"<<endl;
    cout<<"q = search_subject (ex):---> q 189"<<endl;
    cout<<"p = print_subject (ex):---> p"<<endl;

    while(true){
        cin>>mode;
        if(mode == 'a'){
            cin>>sub_key;
            cin>>sub_name;
            s->add_subject(sub_key, sub_name);
        }
        else if(mode == 'i'){
            cin>>sub_key;
            cin>>stu_key;
            cin>>stu_surname;
            cin>>stu_lastname;
            cin>>stu_score;
            s->add_student(sub_key, stu_key, stu_surname, stu_lastname, stu_score);
        }
        else if(mode == 'u'){
            cin>>sub_key;
            s->print_student(sub_key);
        }
        else if(mode == 'p'){
            s->print_subject();
        }
        else if(mode == 'q'){
            cin>>sub_key;
            cout<<s->search_subject(sub_key)<<endl;
        }
        else if(mode == 'e'){
            break;
        }
    }
}