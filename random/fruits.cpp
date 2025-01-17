#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    string fruits[3] = {"orange", "apple", "avocado"};
    ofstream writen("fruits.txt");
    if(writen.is_open()){
        cout<<"file cleaned\n";
    }

    ofstream write("fruits.txt", ios::app);
    if(write.is_open()){
        for(int i = 0; i<3; i++){
            write<<fruits[i]<<"\n";
        }
    }
    write.close();

    string value[3];
    ifstream read("fruits.txt");
    if(read.is_open()){
        for(int c=0; c<3; c++){
            getline(read, value[c]);
        }

    }
    read.close();
    for(int i = 0; i<3; i++){
        cout<<value[i]<<"\t";
    }
}
