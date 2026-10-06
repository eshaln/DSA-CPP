#include <iostream>
using namespace std;
class Node {
public:
    Node *next;
    int data;
    Node(int val) {
        data=val;
        next=nullptr;
    }
};

class List {
    Node *first;
    Node *last;
public:
    List() {
        first=last=nullptr;
    }
    void insert_end(int val) {
        Node *p=new Node(val);
        if (first==nullptr) {
            first=last=p;
        }
        else {
            last->next=p;
            last=p;
        }
    }

    void find_middle() {
        Node *fast;
        fast=first;
        Node *slow;
        slow=first;

        while (fast !=nullptr && fast->next!=nullptr ) {
            fast=fast->next->next;
            slow=slow->next;
        }
        cout<<"The middle node is: "<<slow->data<<endl;

    }
    void print_list() {
        Node *temp;
        temp = first;
        while (temp != nullptr) {
            cout<<temp->data<<" ";
            temp=temp->next;

        }
        cout<<endl;
    }

};

int main() {
    List l1;
    l1.insert_end(1);
    l1.insert_end(2);
    l1.insert_end(3);
    l1.insert_end(4);
    l1.insert_end(5);
    l1.insert_end(6);

    l1.find_middle();
    l1.print_list();

}