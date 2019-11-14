//
// Created by Jordan Deason on 11/07/19.
//
#include "SortedLinkedList.h"

void SortedLinkedList::insertSorted(const Data &d) {
    Node *current = new Node(d);
    Node *tempHead = new Node(Data(0.0, 0.0, 0.0, 0.0), nullptr);
    if (head == nullptr) {//if head is empty
        head = current;//inserts at head
    } else {
        tempHead->next = head;
        Node *location = tempHead;
        //finds value of loc
        //while loop stops at end of the list
        while (location->next != nullptr && location->next->data < current->data) {
            location = location->next;
        }
        current->next = location->next;//inserts into list
        if (location->next == head) {
            head = current;
        }
        location->next = current;
        delete tempHead;//deletes node to free memory
    }
}

void SortedLinkedList::print(ostream &os) {
    return LinkedList::print(os);
}