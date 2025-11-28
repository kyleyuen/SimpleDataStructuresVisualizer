#include "linkedlist.h"
#include <iostream>

using namespace std;

int main() {
    Linkedlist list;

    list.insertHead(5);
    list.insertHead(3);
    list.insertTail(9);

    list.display(); 

    std::cout << "Position of 5: " << list.search(5) << std::endl;

    list.deleteValue(3);
    list.display(); 

    return 0;
}
