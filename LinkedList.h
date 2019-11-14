/* Class: LinkedList
 * Description: Very basic singly linked List class with single head
 * class for use with Data object. It is meant to be inherited for
 * more complex linked lists. (Comes with Node class.)
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Data.h"

class Node {
public:
    Data data;//obj at node
    Node *next;//pointer to next node

    Node(const Data &d, Node *n = nullptr);
};

class LinkedList {
protected:
    Node *head;
public:
    LinkedList();
    LinkedList(const LinkedList& list);
    const LinkedList& operator=(LinkedList rhs);

    virtual void print(ostream &os);
    void pop_head();
    ~LinkedList();
};

#endif //LINKEDLIST_H