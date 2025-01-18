#include<iostream>
using namespace std;

union student
{
    unsigned int ID;
    float GPA;
    short age;
    
};

int main(){

student student1;
student1.ID = 45679;

cout<<student1.ID<<"\n";

student1.GPA = 3.7894;
cout<<student1.GPA;


}