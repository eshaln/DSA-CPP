#include <iostream>
using namespace std;
int main() {
    string cars[5]={"BMV","MAZDA","FORD","VOLVO"};
    cars[1]="Opel";
    for (int i=0;i<5;i++) {
        cout<<cars[i]<<endl;

    }
    return 0;
}