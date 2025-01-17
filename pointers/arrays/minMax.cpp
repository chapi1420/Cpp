#include<iostream>
using namespace std;
void minMAx(int nums[], int size, int*minim, int*maxim){
    cout<<"observing the data given...\n";
    for(int i=0; i<size; i++){
        if(nums[i] < *minim){
            *minim = nums[i];
        }
        if(*(nums+i)>*maxim){///U can use pointers to iterate through a given array.
            *maxim = nums[i];
        }
        
    }
    cout<<"comparision completed\n";
    
}
int main(){
    int nums[5] = {1,2,3,4,5};
    int minim = nums[0];
    int maxim = nums[0];
    minMAx(nums, 5, &minim, &maxim);
    cout<<"minimum value: "<<minim<<endl<<"maximum value: "<<maxim<<endl;
}