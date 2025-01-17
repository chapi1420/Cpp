#include<iostream>
using namespace std;
void accepter(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<"arr[<<"<<i<<">>]\n";
        cin>>*(arr+i);
    }
    cout<<"accepting elements successful!\n";
}
void sumer(int arr[], int size, int& tot){
    int sumer = 0;
    for(int i =0; i<size; ++i){
        sumer += *(arr+i);//this is the same with 'arr[i]'.
    }
    tot = sumer;
}
int main(){
    /*this code will show you the basic implementation 
    of dynamic array and what things you can do with it.*/
    int size, tot;
    cout<<"enter the number of elements you want in your array: ";
    cin>>size;
    int* arr = new int[size];
    accepter(arr, size);
    sumer(arr, size, tot);
    cout<<tot<<endl;
    delete []arr;
    arr = NULL;
    cout<<"dynamic pointer successfully deleted!";
    
    

}