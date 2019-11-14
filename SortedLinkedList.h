//
// Created by Jordan Deason on 11/07/19.
//

#ifndef PROJECT7_JORDANDEASON_SORTEDLINKEDLIST_H
#define PROJECT7_JORDANDEASON_SORTEDLINKEDLIST_H

#include "LinkedList.h"

class SortedLinkedList : public LinkedList {
public:
    void insertSorted(const Data &d);
    void print(ostream &os);
};

#endif //PROJECT7_JORDANDEASON_SORTEDLINKEDLIST_H
