#include <iostream>
#include<string>
using namespace std;

class Node {
public:
    int orderid;
    string r_name;
    string c_address;
    string item_list;
    int prep_time;
    string order_time;
    Node* next;
    Node* prev;

    Node(int oID,string rname,string cAddress,string itemList,int prepTime,string orderTime) {
        orderid = oID;
        r_name = rname;
        c_address = cAddress;
        item_list = itemList;
        prep_time = prepTime;
        order_time = orderTime;
        prev=nullptr;
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

    void addOrder(int oID,string rname,string cAddress,string itemList,int prepTime,string orderTime) {


        Node* n = new Node(oID,rname,cAddress,itemList,prepTime, orderTime);
        if (isEmpty()) {
            front = rear=n;
        }
        else {
            if (prepTime <= 10) {
                n->next=front;
                front->prev=n;
                front=n;
                return;
            }
            rear->next=n;
            n->prev=rear;
            rear=n;
        }
    }

    void dispatch_order() {
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
            front->prev=nullptr;


        }
        delete p;

    }

    void view_order() {
        if (isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Front: "<<front->orderid<<endl;
        cout<<"r_name: "<<front->r_name<<endl;
        cout<<"c_address: "<<front->c_address<<endl;
        cout<<"item_list: "<<front->item_list<<endl;
        cout<<"prep_time: "<<front->prep_time<<endl;

    }
    void display_order() {
        if (isEmpty()) {
            cout<<"Deque is empty"<<endl;
            return;
        }
        Node*t=front;
        while (t!=nullptr) {
            cout<<"Order ID"<<t->orderid<<","<<t->r_name<<","<<t->c_address<<","<<t->prep_time<<endl;
            t=t->next;

        }
        cout<<endl;
    }

    void cancel_order(int orderID) {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* p = front;

        while (p != nullptr) {
            if (p->orderid == orderID) {

                if (p == front && p == rear) {
                    front = rear = nullptr;
                }
                else if (p == front) {
                    front = front->next;
                    front->prev = nullptr;
                }
                else if (p == rear) {
                    rear = rear->prev;
                    rear->next = nullptr;
                }
                else {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                }

                delete p;
                cout << "Order cancelled successfully" << endl;
                return;
            }

            p = p->next;
        }

        cout << "Order ID not found" << endl;
    }
};

int main() {
    Queue q;
    q.addOrder(0,"nnn","Street 4","Burger",12,"10:00");
    q.addOrder(1,"bbb","Street 4","pizza",10,"12:00 PM");
    q.addOrder(2,"sss","Street 5","tacos",20,"1:00 pm");
    q.view_order();
    q.dispatch_order();
    q.display_order();
    q.cancel_order(2);
    q.display_order();
}