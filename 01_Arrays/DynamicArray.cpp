#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<string> cars={"Volvo","BMW","Ford"};
    cars.push_back("Tesla");//adds another element to the vector

    for (int i=0;i<cars.size();i++) {
        cout<<cars[i]<<endl;
    }

    return 0;

}