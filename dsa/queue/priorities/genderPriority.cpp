#include<iostream>
using namespace std;



struct Person {
    string gender;
    Person* next;
};

struct GenderPQ {
    Person* front;
    Person* rear;
};

void init(GenderPQ &q) {
    q.front = q.rear = NULL;
}

void enqueue(GenderPQ &q, string gender) {
    Person* p = new Person();
    p->gender = gender;
    p->next = NULL;

    if (gender == "female") {
        p->next = q.front;
        q.front = p;
        if (q.rear == NULL) q.rear = p;
    }
    else { 
        if (q.rear == NULL) q.front = q.rear = p;
        else {
            q.rear->next = p;
            q.rear = p;
        }
    }
}

string dequeue(GenderPQ &q) {
    if (q.front == NULL) return "empty";

    Person* temp = q.front;
    string val = temp->gender;
    q.front = q.front->next;
    if (q.front == NULL) q.rear = NULL;

    delete temp;
    return val;
}

void display(GenderPQ &q) {
    Person* cur = q.front;
    while (cur != NULL) {
        cout << cur->gender << " ";
        cur = cur->next;
    }
    cout << endl;
}


int main() {
    GenderPQ q;
    init(q);

    enqueue(q, "male");
    enqueue(q, "female");
    enqueue(q, "male");
    enqueue(q, "female");

    cout << "Queue: ";
    display(q);

    cout << "Dequeued: " << dequeue(q) << endl;

    cout << "After dequeue: ";
    display(q);

    return 0;
}
