#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() {
    head = nullptr; //empty list
}

LinkedList::LinkedList(const LinkedList &list) {//copy constructor
    if (list.head) {//deep copy
        Node *current, *currentList;
        head = current = new Node(list.head->data);//copy head node
        currentList = list.head->next;
        while (currentList != nullptr) {//copies data
            current = current->next = new Node(currentList->data);
            currentList = currentList->next;
        }
    } else {
        head = nullptr;//creates empty list if list is empty
    }
}

const LinkedList &LinkedList::operator=(LinkedList rhs) {//assignment operator
    swap(head, rhs.head);//swap function
    return *this;
}

void LinkedList::print(ostream &os) {
    // start at the head of the list
    Node *current = head;
    while (current != nullptr) {
        os << current->data << endl; // use overloaded output operator to print
        current = current->next; // go to next node in list
    }
}
void LinkedList::pop_head() {
    // if not an empty list
    if (head != nullptr) {
        Node *current = head;//loc of where head points
        head = head->next;//head points to next node
        delete current;//delete node to free space
    }
}
LinkedList::~LinkedList() {
    while (head != nullptr) {//pops until the list is empty
        pop_head();
    }
}

Node::Node(const Data &d, Node *n) {
    data = d;
    next = n;
}