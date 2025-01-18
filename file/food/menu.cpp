#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    string bfst[] = {"scrambled_egg", "pancake", "cake"};
    string lunch[]= { "pizza", "burger", "grilled_meat"};
    string dinner[]= {"salad", "fish_cotelete", "soup"};
    //breakfast
    ofstream Bfast("break fast.txt", ios::app);
    if(Bfast.is_open()){
        for(int i =0; i<3; i++){
            Bfast<<bfst[i]<<"\n";
        }
    }
    Bfast.close();
    //lunch
    ofstream Lunch("lunch.txt", ios::app);
    if(Lunch.is_open()){
        for(int i =0; i<3; i++){
            Lunch<<lunch[i]<<"\n";
        }
    }
    Lunch.close();
    //dinner
    ofstream Dinner("dinner.txt", ios::app);
    if(Dinner.is_open()){
        for(int i =0; i<3; i++){
            Dinner<<dinner[i]<<"\n";
        }
    }
    Dinner.close();
    //menu
    string value;
    string reads[] = {"break fast.txt", "lunch.txt", "dinner.txt"};
    ofstream write("menu.txt", ios::app);
    if(write.is_open()){
        for(int i=0; i<3; i++){
        ifstream read(reads[i]);
        if(read.is_open()){
            while (getline(read, value)) { 
                write<<value<<"\n";
            }     
            

        }
    }
    
    }
    }


