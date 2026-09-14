#include <vector>
#include<iostream>
using namespace std;


vector<int>list;

void insertAtEnd(int value) {
    list.push_back(value);
}

void insertAtBeginning(int value) {
    list.insert(list.begin(),value);
}
void insertAfter(int specific,int value) {
    for (int i=0;i<list.size();i++) {
        if (list[i]==specific) {
            list.insert(list.begin()+i+1,value);
            return;
        }
    }
}
void insertBefore(int specific,int value) {
    for (int i=0;i<list.size();i++) {
        if (list[i]==specific) {
            list.insert(list.begin()+i,value);
            return;
        }
    }
}
void display() {
    for (int number: list){

        cout<<number<<" ";
    }
}
void deleteFromBeginning() {
    if (!list.empty()) {
        list.erase(list.begin());
    }
}
void deleteFromEnd() {
    if (!list.empty()) {
        list.pop_back();
    }
}

void deleteFromSpecificValue(int value) {
    if (!list.empty()) {
        for (int i=0;i<list.size();i++) {
            if (list[i]==value) {
                list.erase(list.begin()+i);

            }
        }
    }
}


int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);



   insertAtBeginning(1);
    insertAtBeginning(2);

    insertAfter(3,40);
    insertBefore(4,10);
    cout<<"Display list:"<<endl;

    deleteFromBeginning();
    deleteFromEnd();
    deleteFromSpecificValue(10);

    cout<<"After deleting:"<<endl;
    display();




}