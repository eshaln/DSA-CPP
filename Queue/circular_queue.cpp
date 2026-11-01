#include <iostream>
using namespace std;

class car {
    public:
    int carNo;
    int slotno;
};
class Circular_Queue {
public:
    car arr[5];
    int front,rear,count;

    Circular_Queue() {
        front=0;
        rear=-1;
        count=0;
    }

    bool isEmpty() {
        return count==0;

    }
    bool isFull() {
        return count==5;
    }

    void park_car() {
        if (isFull()) {
            cout<<"Parking queue is full"<<endl;
            return;
        }
        int no;
        cout<<"Enter car no:";
        cin>>no;

    rear=(rear+1)%5;
        arr[rear].carNo=no;
        int slotno;
        cout<<"Enter slot no:";
        cin>>slotno;
        arr[rear].slotno=slotno;
        cout<<"Car parked ,car no:"<<arr[rear].carNo<<" Slot:"<<arr[rear].slotno<<endl;
        count++;
    }
    void dequeue() {
        if (isEmpty()) {
            cout<<"Parking queue is empty"<<endl;
            return;
        }
        cout<<"Dequeuing :"<<arr[front].carNo<<endl;
        front=(front+1)%5;
        count--;

    }

};
int main() {
    Circular_Queue q;
    q.park_car();


}