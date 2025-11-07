#include<iostream>
using namespace std;

struct Node{
Node* prev;
int data;
Node* next;
};

void insertBeginning(Node*& head, int num)
{
Node* newNode = new Node();
newNode-> data =num;
newNode->next =head;
head->prev =newNode;
head =newNode;
newNode->prev =nullptr;
}


void insertEnd(Node*& head, int num)
{
    Node* newnode =new Node();
    newnode->data = num;
    newnode->next =nullptr;

    if(head ==nullptr){
        head =newnode;
        return;
    }

    Node* temp =head;
    while (temp->next != nullptr){
        temp =temp->next;
    }

    temp->next =newnode;
    newnode->prev =temp->next;

}


void insertMid(Node*& head, int position, int num)
{
    if(position <= 1){
        insertBeginning(head, num);
    }
Node* newNode =new Node();
newNode->data =num;
Node* temp = head;
for (int i = 1; temp != nullptr && i < position - 1; i++) {
    temp = temp->next;
}

if (temp == nullptr) {
    cout << "Position out of range!" << endl;
    delete newNode;
    return;
    }
temp->next->prev =newNode;
newNode->next = temp->next;
newNode->prev =temp;
temp->next = newNode;

}


void deleteBeg(Node*& head)
{
if(head ==nullptr){
    cout<<"the linked lisst is empty, nothing to delete"<<endl;
    return;
    }
Node* temp =head;
head =head->next;
delete temp;
head->prev =nullptr;
}


void deleteEnd(Node*& head)
{ if(head==nullptr){
    cout<<"nothing to delete, list is already empty"<<endl;
}
if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp =head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    temp->next->prev =nullptr;
    delete temp->next;
    temp->next = nullptr;


}


void deleteMid(Node*& head, int position)
{
Node* 
}


int main(){
    Node* head;
}
