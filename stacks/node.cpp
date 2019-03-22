//
// Created by Rafa on 3/21/2019.
//

#include <iostream>
#include "node.h"

stacks::node::node() {
    dataPtr = next = nullptr;
}

stacks::node::~node() { // This has to be created, even though it is purely virtual.
    bool debug = true;
    if (debug)
        std::cout<< "\nNode destructor called\n";
}

stacks::node::node(void *ptr) { // Constructor with data initialization
    dataPtr = ptr;
    next = nullptr;
}

stacks::node::node(const stacks::node &other) {
    copy(other);
}

stacks::node &stacks::node::operator=(const stacks::node &other) {
    if (this!=&other) // do i have to nuke?
        copy(other);
    return *this;
}

void *stacks::node::access() const {
    return dataPtr;
}

stacks::node *stacks::node::getNext() {
    return next;
}

void stacks::node::setNext(stacks::node *ptr) {
    next = ptr;
}

void stacks::node::copy(const stacks::node &other) {
    makeCopy(other);
}

void stacks::node::setData(void *ptr) {
    dataPtr = ptr;
}

