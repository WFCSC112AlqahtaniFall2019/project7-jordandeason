//
// Created by Jordan Deason on 11/07/19.
//
#include "Queue.h"

Queue::Queue() {//constructor
    head = nullptr;
    tail = nullptr;
}

void Queue::enqueue_tail(const Data &d) {//adding data to tail
    Node *newNode = new Node(d);
    if (tail == nullptr) {//if queue is empty
        tail = newNode;
        head = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

}

bool Queue::dequeue_head() {//adding data to head
    if (head == nullptr)//if queue is empty
        return false;
    else if (head->next != nullptr) {
        Node *current = head;//loc where head points
        head = head->next;//points to next node
        delete current;//delete node to free memory
        return true;
    } else {
        return false;
    }
}

Data Queue::print() {
    return head->data;//returns head data
}