#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

class Linkedlist{
private:
    struct Node{
        int val; 
        Node* next;
    };

    Node* head;

public:
    Linkedlist();
    ~Linkedlist();
    void insertHead(int val);
    void insertTail(int val);
    bool deleteValue(int val);

    int search(int val);
    void display() const;
};

#endif