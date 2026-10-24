#include<iostream>
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
    void push_back(int value) {
        Node *newNode=new Node(value);

        if (head==NULL){
            head = tail = newNode;

        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void split_list(clist& l1,clist& l2) {
        if (head==nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }

        int count=0;
        Node* temp=head;
        while (temp!=nullptr) {
            count++;
            temp=temp->next;
        }
        int half=count/2;
        temp=head;
        for (int i=0;i<half;i++) {
            l1.push_back(temp->data);
            temp=temp->next;
        }
        while (temp!=nullptr) {
            l2.push_back(temp->data);
            temp=temp->next;
        }

    }
    void sort() {
        for (Node* i=head;i!=NULL;i=i->next) {
            for (Node*j=i->next;j!=NULL;j=j->next) {
                if (i->data<j->data) {
                    swap(i->data,j->data);
                }
            }
        }

    }
    void display() {
        if (head==nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=head;
        while (temp!=nullptr) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }

    }
};
int main() {
    clist l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);
    l.push_back(60);
    clist l1;
    clist l2;
    l.split_list(l1,l2);
    cout<<"Sorting list one in descending order:";
    l1.sort();
    l1.display();
    cout<<endl;
    cout<<"Sorting list two in descending order:";
    l2.sort();

    l2.display();

}