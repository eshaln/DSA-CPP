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
            void push_front(int value) {
                Node *newNode=new Node(value);

            if (head==NULL){
                    head = tail = new Node(value);
                    return;
                }
                else{
                    newNode->next = head;
                    head = newNode;
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
    ls.push_front(5);
    ls.push_front(6);
    ls.push_front(7);
    ls.display();

}