//
// Created by Jordan Deason on 11/07/19.
//

#include "Stack.h"

Stack::Stack() {//constructor

    head = nullptr;
}

bool Stack::pop_head() {
    if (head == nullptr)
        return false;
    else if (head->next != nullptr) {
        // save location of where head points
        Node *curr = head;
        head = head->next;// head points to next node
        delete curr;//delete node to free memory
        return true;
    } else {
        return false;
    }

}

void Stack::push_head(const Data &d) {//inserts at head
    Node *newNode = new Node(d);//creates new node
    if (head == nullptr) {//insert at head
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

Data Stack::print() {
    return head->data;//returns head data
}