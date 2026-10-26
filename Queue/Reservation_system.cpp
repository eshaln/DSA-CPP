#include <iostream>
using namespace std;

class Node {
public:
    string name;
    string category;
    int seat_no;
    Node* next;
    Node* prev;

    Node(string n,string c,int sn) {
        name=n;
        category=c;
        seat_no=sn;
        next=nullptr;
        prev=nullptr;

    }
};
class Deque {
public:
    Node* front;
    Node* rear;
    int count;
    const int capacity=5;
    Deque() {
        front = nullptr;
        rear = nullptr;
    }
    bool isEmpty() {
        return front == nullptr;

    }
    bool isFull() {
        return count==capacity;

    }
    void book_front(string name,string category,int seat_no) {

        if (isFull()) {
            cout<<"Deque is full"<<endl;
            return;
        }
        Node* n=new Node(name,category,seat_no);
        if (isEmpty()) {
            front=rear=n;
            n->next=n;
            n->prev=n;
        }
        else {
            n->next=front;
            n->prev=rear;
            rear->next=n;
            front->prev=n;
            front=n;

        }
        count++;
    }


    void book_at_rear(String name,String category,int seat_no) {
        if (isFull()) {
            cout<<"Deque is full"<<endl;
            return;
        }
        Node* n=new Node(name,category,seat_no);
        if (isEmpty()) {
            front=rear=n;
            n->next=n;
            n->prev=n;

        }
        else {
            rear->next=n;
            n->prev=rear;
            n->next=front;
            front->prev=n;
            rear=n;
        }
    }
    void cancel_from_front() {
        if (isEmpty()) {
            cout<<"Deque is empty"<<endl;
            return;
        }
        Node* p=front;
        if (front==rear) {
            front=rear=nullptr;

        }
        else {
            front=front->next;
            front->prev=rear;
            rear->next=front;

        }
        delete p;
        count--;
    }
    void cancel_from_rear() {
        if (isEmpty()) {
            cout<<"Deque is empty"<<endl;
            return;
        }
        Node* p=rear;
        if (front==rear) {
            front=rear=nullptr;

        }
        else {
            rear=rear->prev;
            rear->next=front;
            front->prev=rear;

        }
        delete p;
        count--;
    }




    void display_front_reservation() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Front: "<<front->name<<","<<front->category<<","<<front->seat_no<<endl;
    }

    void view_rear_reservation() {
        if (isEmpty()) {
            cout<<"Deque is empty"<<endl;
            return;
        }
        cout<<"Rear: "<<rear->name<<","<<rear->category<<","<<rear->seat_no<<endl;
    }

    void display() {
        if (isEmpty()) {
            cout<<"Deque is empty"<<endl;
            return;
        }
        Node*t=front;
        while (t!=nullptr) {
            cout<<"Front: "<<t->name<<","<<t->category<<","<<t->seat_no<<endl;
           t=t->next;

        }
        cout<<endl;
    }
};

int main() {
    Deque q;
    q.book_front("Alishba","VIP",22);
    q.book_front("Asra","VIP",15);

    q.book_at_rear("Sara","Economy",12);

    q.display();
    cout<<"Display front reservation:";
    q.display_front_reservation();
    q.view_rear_reservation();
    cout<<endl;
    q.cancel_from_front();
    q.cancel_from_rear();
    q.display();


}
