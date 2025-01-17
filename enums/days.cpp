#include<iostream>
#include<cctype>

using namespace std;
enum Days{
    Sunday,
    Monday, 
    Tuesday, 
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int  dayChech(string day){
    if(day=="monday") return Monday;
    else if(day=="tuesday")return Tuesday;
    else if(day=="wednesday")return Wednesday;
    else if(day=="thursday")return Thursday;
    else if(day=="friday")return Friday;
    else if(day== "saturday")return Saturday;
    else if(day=="sunday")return Sunday;
    else return -1;
}



int main(){
    string day;
cout<<"enter a day, and I will tell you the number of the day.";
cin>>day;
for(char &c: day){
    c = tolower(c);
}
cout<< day<<" is "<< dayChech(day)<<"th day of the week";


}