#include "doublylinkedlist.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void DoublyLinkedList::insertHead(int val) {
    Node* newNode = new Node(val);

    if (!head) {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void DoublyLinkedList::insertTail(int val) {
    Node* newNode = new Node(val);

    if (!tail) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

bool DoublyLinkedList::deleteValue(int val) {
    if (!head) return false;

    Node* current = head;

    while (current && current->data != val)
        current = current->next;

    if (!current) return false;

    if (current == head) {
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
    }

    else if (current == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    }

    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    return true;
}

int DoublyLinkedList::search(int val) const {
    Node* current = head;
    int pos = 1;

    while (current) {
        if (current->data == val) return pos;
        current = current->next;
        pos++;
    }

    return -1;
}

void DoublyLinkedList::displayForward() const {
    Node* current = head;
    while (current) {
        std::cout << current->data;
        if (current->next) std::cout << " <-> ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::displayBackward() const {
    Node* current = tail;
    while (current) {
        std::cout << current->data;
        if (current->prev) std::cout << " <-> ";
        current = current->prev;
    }
    std::cout << std::endl;
}
