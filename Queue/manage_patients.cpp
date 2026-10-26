#include <iostream>
using namespace std;

class Node {
public:
    string name;
    int ID;
    string doc_name;
    string time;
    Node* next;

    Node(string n,int id,string dname,string t) {
        name=n;
        doc_name=dname;
        ID=id;
        time=t;
        next=nullptr;

    }
};
class Queue {
    public:
    Node* front;
    Node* rear;
    Queue() {
        front = nullptr;
        rear = nullptr;
    }
    bool isEmpty() {
        return front == nullptr;

    }
    void addPatient(string name,int ID,string doc_name,string time) {
        Node* p = new Node(name,ID,doc_name,time);


        if (isEmpty()) {
            front=rear=p;

        }
        else {
            rear->next=p;
            rear=p;
        }
    }

    void removePatient() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp = front;
        cout<<"Removing: "<<temp->name<<","<<temp->ID<<endl;
        front=front->next;
        delete temp;

        if (front==nullptr) {
            rear=nullptr;
        }

    }
    void display_front_patient() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Front: "<<front->name<<","<<front->ID<<endl;
    }

    void display() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node*t=front;
        while (t!=nullptr) {
            cout<<"Name: "<<t->name<<","<<t->ID<<endl;
           t=t->next;

        }
        cout<<endl;
    }
};

int main() {
    Queue q;

    q.addPatient("Ali", 101, "Dr. Ahmed", "09:00 AM");
    q.addPatient("Sara", 102, "Dr. Fatima", "09:15 AM");
    q.addPatient("Usman", 103, "Dr. Bilal", "09:30 AM");

    cout << "All waiting patients:" << endl;
    q.display();

    cout << "\nNext patient:" << endl;
    q.display_front_patient();

    cout << "\nCalling next patient:" << endl;
    q.removePatient();

    cout << "\nRemaining patients:" << endl;
    q.display();

    return 0;
}