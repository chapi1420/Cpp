#include<iostream>
using namespace std;
struct student{
    string name;
    string id;
    float mark; 
    string department = "undefined";
    struct courses{
        string SubjectName;
        int credit

    };
    student(string name, string id, float mark){
        this -> name = name;
        this -> id = id;
        this ->mark = mark;
    }

};
void display(student entry){
        cout<<entry.name<<"\n "<<entry.id<<"\n "<<entry.mark<<" \n"<<entry.department;
}
int main(){
    student s1("chpi", "0358", 95);
    display(s1);

}