//
// Created by Rafa on 3/21/2019.
//

#ifndef CS008_BASESTACK_H
#define CS008_BASESTACK_H

#include "node.h"
#include <cstddef>


namespace stacks {

enum BASESTACK_ERRORS{BASE_EMPTY, BASE_FULL, BAD_STACK_SIZE};

class baseStack {

public:
    baseStack(unsigned int capacity = 5);
    ~baseStack();
    baseStack(const baseStack &other);
    baseStack& operator=(const baseStack&other);

    bool isFull() const;
    bool isEmpty() const;
    size_t size() const;
    void resize(unsigned int newSize);

protected:
    void push(node *ptr);
    node* pop();
    node* top();
    virtual void nukem() = 0; // TODO: rename

private:
    size_t capacity, mySize;
    node *tos;



};

}


#endif //CS008_BASESTACK_H
