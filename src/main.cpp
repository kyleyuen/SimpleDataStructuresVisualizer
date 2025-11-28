#include "linkedlist.h"
#include "doublylinkedlist.h"

#include <iostream>

using namespace std; 

int main() {
    Linkedlist list1;

    list1.insertHead(5);
    list1.insertHead(3);
    list1.insertTail(9);

    list1.display(); 

    cout << "Position of 5: " << list1.search(5) << endl;

    list1.deleteValue(3);
    list1.display(); 

    DoublyLinkedList list2;

    list2.insertHead(5);
    list2.insertHead(3);
    list2.insertTail(10);
    list2.insertTail(12);

    list2.displayForward();
    list2.displayBackward();

    list2.deleteValue(10);
    list2.displayForward();  

    cout << "Search 5: " << list2.search(5) << endl;

    return 0;
}
