#include<iostream>
using namespace std;
void acceptor(int** table, int rows, int columns){
    for(int i=0; i<rows; i++)
    {
        for(int j =0; j<columns; ++j)
        {
            cout<<"enter the "<<i<<"th row "<<j<<"th column: ";
            cin>>table[i][j];
        }
    }
}
void printer(int** table, int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j =0; j<columns; j++){
            cout<<table[i][j]<<"\t\t";
        }
        cout<<endl;
    }

}
int main(){
    //table-> rows-> columns
    int rows, columns;
    cout<<"enter <rows><columns>";
    cin>>rows>>columns;
    int **table = new int*[rows];// '**' stands for a pointer that is used to pint into another pointer.
    for(int i=0; i<rows; i++){
        table[i] = new int[columns];
    }
    acceptor(table, rows, columns);
    printer(table, rows, columns);

    // delete the dynamic arrays created 
    for(int i=0; i<rows; i++){
        delete[] table[i];
    }
    delete[] table;
    table = NULL;


}