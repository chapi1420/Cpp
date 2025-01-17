#include<iostream>
using namespace std;
int main(){
    int luckynum[5] = {1, 3, 5, 2, 7};
    cout<<luckynum<<endl;// address of the first element in the array is printed.
    cout<<luckynum[1]<<endl;//the second element in the array is printed. we can say the square bracket is used to dereference the 'luckynum'.
    cout<<*(luckynum+2)<<endl;//this is the proof the above hypothesis is true we can use both pointers and square brackets to dereference the elements in an array.
    
}