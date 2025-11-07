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
Node* newNode =new Node();
newNode->data =num;


}


void deleteBeg(Node*& head)
{

}


void deleteEnd(Node*& head)
{

}


void deleteMid(Node*& head, int position)
{

}


int main(){
    Node* head;
}
