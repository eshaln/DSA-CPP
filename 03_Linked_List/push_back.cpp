#include <iostream>
using namespace std;


class Node {
public :int data;
public :Node* next;

public:
    Node(int value) {
        data = value;
        next = NULL;

    }
};
class sList {
    Node* head;
    Node* tail;

public:
    sList() {
        head = NULL;
        tail = NULL;
    }
    void push_back(int value) {
        Node *newNode=new Node(value);

        if (head==NULL){
            head = tail = new Node(value);
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        Node *temp=head;
        while(temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main() {
    sList ls;
    ls.push_back(5);
    ls.push_back(6);
    ls.push_back(7);
    ls.display();

}