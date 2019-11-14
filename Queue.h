//
// Created by Jordan Deason on 11/07/19.
//

#ifndef PROJECT7_JORDANDEASON_QUEUE_H
#define PROJECT7_JORDANDEASON_QUEUE_H

#include "LinkedList.h"

class Queue : public LinkedList {
public:
    Queue();

    bool dequeue_head();

    void enqueue_tail(const Data &d);

    Data print();

private:
    Node *tail;
};

#endif //PROJECT7_JORDANDEASON_QUEUE_H
