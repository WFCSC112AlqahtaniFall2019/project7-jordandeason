//
// Created by Jordan Deason on 11/07/19.
//

#ifndef PROJECT7_JORDANDEASON_STACK_H
#define PROJECT7_JORDANDEASON_STACK_H

#include "LinkedList.h"

class Stack : public LinkedList {
public:
    Stack();

    void push_head(const Data &d);

    bool pop_head();

    Data print();
};

#endif //PROJECT7_JORDANDEASON_STACK_H
