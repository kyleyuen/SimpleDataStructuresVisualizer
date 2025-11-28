#include "linkedlist.h"
#include <iostream>

using namespace std; 

Linkedlist::Linkedlist(){
    head = nullptr;
}

Linkedlist::~Linkedlist(){
    Node* temp = head;
    while( temp != nullptr){
        Node* curr = temp;
        temp = temp -> next;
        delete curr; 
    }
}

void Linkedlist::insertHead(int val){
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void Linkedlist::insertTail(int val){
    Node* newNode = new Node();
    newNode->val = val;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

bool Linkedlist::deleteValue(int val) {
    if (!head) return false;

    if (head->val == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next && current->next->val != val)
        current = current->next;

    if (current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        return true;
    }

    return false;
}

int Linkedlist::search(int val) {
    Node* current = head;
    int pos = 1;
    while (current) {
        if (current->val == val) return pos;
        current = current->next;
        pos++;
    }
    return -1;
}

void Linkedlist::display() const {
    Node* current = head;
    while (current) {
        std::cout << current->val;
        if (current->next) std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}



