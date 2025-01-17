#include<iostream>
using namespace std;
void print(void*ptr, char type){
    switch (type)
    {
    case 'i':cout<<*((int*)ptr)<<endl;break;
    case 'f':cout<<*((float*)ptr)<<endl;break;
    case 'c':cout<<*((char*)ptr)<<endl;break;
    
    default:cout<<"you gave me invalid input"; break;
    }
}
int main(){
    char a = 'k';
    int num = 5;
    float f = 5.6;
    print(&a, 'c');
    print(&f, 'f');
    print(&num, 'i');
}