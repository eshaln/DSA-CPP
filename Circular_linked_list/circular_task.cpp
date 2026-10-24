#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
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
    void add_stop(int value) {

        Node* new_node = new Node(value);
        if (head == NULL) {
            head = tail=new_node;
            tail->next = head;
            return;
        }
        tail->next = new_node;
        new_node->next = head;
        tail = new_node;
    }

    void find_middle_node() const {
        if (head == NULL) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* fast= head;
        Node* slow=head;

        while (fast->next!=head && fast->next->next!=head) {
            fast=fast->next->next;
            slow=slow->next;
        }
        if (fast->next->next==head) {
            slow=slow->next;
        }
        cout<<"Middle node found: "<<slow->data<<endl;
    }


    void split_list(clist& fh ,clist& sh) {
        int count=0;

        if (head == NULL) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=head;
        do{
            count++;
            temp=temp->next;
        }while (temp!=head);
        int h=(count+1)/2;
        temp=head;
        for (int i=0;i<h;i++) {
            fh.add_stop(temp->data);
            temp=temp->next;
        }
        for (int i=h;i<count;i++) {
            sh.add_stop(temp->data);
            temp=temp->next;
        }
    }
    void print_list() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp;
        temp = head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;

        }while (temp!=head);
        cout<<endl;
    }

    void divideCircle() {
        if (head == NULL)
            return;


        if (head->next == head) {
            cout << "Participant: " << head->data << endl;
            return;
        }

        clist firstHalf;
        clist secondHalf;

        split_list(firstHalf, secondHalf);

        firstHalf.divideCircle();
        secondHalf.divideCircle();
    }


};

int main() {
    clist cl;
    clist fh;
    clist sh;
    cl.add_stop(10);
    cl.add_stop(20);
    cl.add_stop(30);
    cl.add_stop(40);
    cl.add_stop(50);
    cl.add_stop(60);
    cl.add_stop(70);
    cl.add_stop(80);

    cl.find_middle_node();
    cl.split_list(fh,sh);

    cl.print_list();
    cout<<"Recursive division:";
    cl.divideCircle();

}