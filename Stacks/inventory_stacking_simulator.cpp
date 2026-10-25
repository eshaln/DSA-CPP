#include <iostream>
using namespace std;
class Stack {
    struct Node {
        string boxID;
        double weight;
        Node* next;
    }*p;
public:
    void addBox(string,double);
    void remove_top_box();
    void display_Stack();
    void view_top_box();
    void push(string,double);

    Stack() {
        p=NULL;
    }
};
void Stack::push(string ID,double weight) {
   Node *t=new Node;
    t->boxID=ID;
    t->weight=weight;
    t->next=p;
    p=t;


}
void Stack::remove_top_box() {
    if (p==NULL) {
        cout<<"Stack is empty"<<endl;
        return;
    }
    Node* t=p;
    p=p->next;
    delete t;
    return;
}
void Stack::addBox(string id,double weight) {
    Stack temp;
    while (p!=NULL && p->weight < weight) {
        temp.push(p->boxID,p->weight);
        remove_top_box();
    }
    push(id,weight);
    while (temp.p != NULL) {
        push(temp.p->boxID, temp.p->weight);
        temp.remove_top_box();
    }



}
void Stack::view_top_box() {
    if (p==NULL) {
        cout<<"Stack is empty"<<endl;
        return;
    }
   cout<<"Box ID:"<<p->boxID<<endl;
    cout<<"Weight:"<<p->weight<<endl;
}
void Stack::display_Stack() {
    if (p == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }

    Node* t = p;

    while (t != NULL) {
        cout << "BOX ID : " << t->boxID << endl;
        cout << "WEIGHT: " << t->weight << endl;

        cout << "------------------" << endl;

        t = t->next;
    }
}
int main() {
    Stack s;

    s.addBox("A", 2);
    s.addBox("B", 5);
    s.addBox("C", 8);
    s.addBox("D", 6);

    cout << "Top Box:" << endl;
    s.view_top_box();

    cout << "\nFinal Stack (Top to Bottom):" << endl;
    s.display_Stack();

    cout << "\nRemoving top box..." << endl;
    s.remove_top_box();

    s.display_Stack();

    return 0;
}