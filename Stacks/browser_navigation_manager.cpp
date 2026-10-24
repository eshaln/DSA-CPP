#include <iostream>
using namespace std;
class Stack {
    struct Node {
        string title;
        string url;
        string time;
        Node* next;
    }*p;
    public:
    void visitPage(string,string,string);
    void pop();
    void display();
    void display_recent_page();

    Stack() {
        p=NULL;
    }
};
void Stack::visitPage(string title,string url,string time) {
    Node* t = new Node;

    t->title = title;
    t->url = url;
    t->time = time;
    t->next = p;
    p = t;
}
void Stack::pop() {
    if (p==NULL) {
        cout<<"Stack is empty"<<endl;
        return;
    }
    Node* t=p;
    p=p->next;
    delete t;
    return;

}
void Stack:: display_recent_page() {
    if (p==NULL) {
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"Current Page"<<p->title;
    cout<<"Page URL"<<p->url;
    cout<<"Time"<<p->time;

}
void Stack::display() {
    if (p == NULL) {
        cout << "Stack is empty" << endl;
        return;
    }

    Node* t = p;

    while (t != NULL) {
        cout << "Title: " << t->title << endl;
        cout << "URL: " << t->url << endl;
        cout << "Time: " << t->time << endl;
        cout << "------------------" << endl;

        t = t->next;
    }
}
int main() {
    Stack s;
    s.visitPage("Google", "google.com", "10:00 AM");
    s.visitPage("YouTube", "youtube.com", "10:30 AM");
    s.visitPage("GitHub", "github.com", "11:00 AM");

    s.display_recent_page();
    cout<<"Complete browser history:"<<endl;
    s.display();
    cout<<"Going back";
    s.pop();

    s.display_recent_page();
    s.display();
}