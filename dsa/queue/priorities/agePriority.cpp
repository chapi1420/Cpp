#include<iostream>
using namespace std;



struct PersonAge {
    int age;
    PersonAge* next;
};

struct AgePQ {
    PersonAge* front;  // highest age at front
};

void init(AgePQ &q) {
    q.front = NULL;
}

void enqueue(AgePQ &q, int age) {
    PersonAge* p = new PersonAge();
    p->age = age;
    p->next = NULL;

    // insert at front
    if (q.front == NULL || age > q.front->age) {
        p->next = q.front;
        q.front = p;
        return;
    }

    PersonAge* curr = q.front;
    while (curr->next != NULL && curr->next->age >= age)
        curr = curr->next;

    p->next = curr->next;
    curr->next = p;
}

int dequeue(AgePQ &q) {
    if (q.front == NULL) return -1;

    PersonAge* temp = q.front;
    int val = temp->age;
    q.front = q.front->next;

    delete temp;
    return val;
}

void display(AgePQ &q) {
    PersonAge* c = q.front;
    while (c != NULL) {
        cout << c->age << " ";
        c = c->next;
    }
    cout << endl;
}
