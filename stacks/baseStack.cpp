//
// Created by Rafa on 3/21/2019.
//

#include <iostream>
#include "baseStack.h"

stacks::baseStack::baseStack(unsigned int cap) :
    capacity(0),
    mySize(0),
    tos(nullptr)
{
//    bool debug = true;
//    if (debug)
//        std::cout << "\nbaseStack constructed\n";

    resize(cap);
}

stacks::baseStack::~baseStack() {
    tos = nullptr;
    mySize = capacity = 0;

}

stacks::baseStack::baseStack(const stacks::baseStack &other) {

}

stacks::baseStack &stacks::baseStack::operator=(const stacks::baseStack &other) {

}

bool stacks::baseStack::isFull() const {
    return capacity == mySize;
}

bool stacks::baseStack::isEmpty() const {
    return !tos;
}

size_t stacks::baseStack::size() const {
    return mySize;
}

void stacks::baseStack::resize(unsigned int newSize) {
    if (newSize < 1)
        throw BAD_STACK_SIZE;
    if (!tos || newSize >= capacity) // if not empty or newSize is not bigger than current cap
        capacity = newSize;
    else {
        while(mySize > newSize)
            nukem();
        capacity = newSize;
    }
}

void stacks::baseStack::push(stacks::node *ptr) {
    if (isFull())
        throw BASE_FULL;
    ptr->setNext(tos);
    tos = ptr;
    ++mySize;
}

stacks::node *stacks::baseStack::pop() {
    node* popNode = top();
    tos = tos->getNext();
//    tos->setNext(tos->getNext()); TODO: REMOVE
    --mySize;
    return popNode;
}

stacks::node *stacks::baseStack::top() {
    if (isEmpty())
        throw BASE_EMPTY;
    return tos;
}
