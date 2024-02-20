#include <iostream>
#include <vector>
using namespace std;
#include "List.h"

int main() {
    
    List<int> list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.print();
    list.removeLast();
    list.print();
    cout << list.getSize() << endl;
    cout << list.getData(0) << endl;
    list.removeLast();
    
    try {
        cout << list.getMax() << endl;
        cout << "Siguiente instrucción - 1" << endl;
        list.removeLast();
        cout << list.getMax() << endl;
        cout << "Siguiente instrucción - 2" << endl;
    } catch (out_of_range &error) {
        cout << error.what() << endl;
    }

    return 0;
}