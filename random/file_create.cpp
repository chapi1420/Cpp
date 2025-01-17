#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    string name;
    cout<<"what is  your name?";
    getline(cin, name);
    ofstream write("files.txt", ios::app);
    if(write.is_open()){
        write<<name<<endl;
        write.close();
    }
    string value;
    ifstream read("files.txt");
    if(read.is_open()){
        getline(read, value);
        read.close();
        cout<<"my name is: "<<value<<endl;
    }

}