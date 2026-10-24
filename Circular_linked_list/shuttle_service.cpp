#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    string name;
    int distance;
    Node(int id,string n,int d) {
        name=n;
        data = id;
        distance = d;
        next = NULL;

    }


};
class clist {
public:
    Node* head;
    Node* tail;
    clist() {
        head = NULL;
        tail = NULL;
    }
    void add_stop(int id,string name,int distance) {
        Node* new_node = new Node(id,name,distance);
        if (head == NULL) {
            head = tail=new_node;
            tail->next = head;
            return;
        }
        tail->next = new_node;
        new_node->next = head;
        tail = new_node;
    }

    void add_after(int id,int nid,string new_Name,int distance) {
        Node* temp=head;
        if (head==NULL) {
            cout<<"List is empty"<<endl;
            return;
        }
        do{
            if (temp->data == id) {
                Node*p = new Node(nid,new_Name,distance);
                p->next=temp->next;
                temp->next = p;

                if (temp==tail) {
                    tail = p;

                }
                tail->next=head;
                return;
            }
            temp = temp->next;
        }while (temp != head);

        cout<<"Not found";
    }

    void remove_stop(int id) {

        if (head==nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }
        if (head->data == id) {
            Node* temp=head;
            if (head==tail) {
                head=tail=nullptr;

            }
            else {
                head = head->next;
                tail->next = head;
            }
            delete temp;
            return;
        }
        Node* temp = head;

        while (temp->next != head && temp->next->data != id) {
            temp = temp->next;
        }

        if (temp->next == head) {
            cout << "Not Found" << endl;
            return;
        }

        Node* p = temp->next;
        temp->next = p->next;

        if (p == tail) {
            tail = temp;
        }

        tail->next = head;
        delete p;
    }

    void display() {
        Node* temp = head;
        if (head==nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }
        do {
            cout<<"ID:"<<temp->data<<" "
            <<"Name:"<<temp->name<<" "
            <<"Distance:"<<temp->distance<<endl;
            temp = temp->next;

        }while (temp != head);
    }
    void longest_distance() {
        if (head==nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=head;
        Node* longest = head;

        do {
            if (temp->distance>longest->distance) {
                longest = temp;
            }
            temp = temp->next;
        }while (temp != head);
        cout<<"Longest distance stop:"<<longest->name<<",Longest distance:"<<longest->distance<<endl;
    }
};
int main() {
    clist cl;
    cl.add_stop(0,"Main gate",1);
    cl.add_stop(1,"2 gate",2);
    cl.add_stop(2,"3 gate",3);
    cl.add_after(1,5,"4 gate",4);
    cl.remove_stop(0);
    cl.display();
    cl.longest_distance();

}