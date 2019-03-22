//
// Created by rafab on 3/21/2019.
//

#ifndef CS008_MYSTACK_H
#define CS008_MYSTACK_H

#include <iosfwd>
#include <iostream>
#include "baseStack.h"
#include "myNode.h"

namespace stacks{

template <typename T>
class myStack : public baseStack {
public:
    myStack(int cap = 5);
    ~myStack();
    myStack(const myStack<T> &other);
    myStack<T>& operator=(const myStack<T> &other);
    T pop();
    void push(const T& data);
    T top();

    template<typename U>
    friend
    std::ostream& operator<<(std::ostream& out, const myStack<U> &theStack)   ;

    template<typename U>
    friend
    std::istream& operator>>(std::istream& in, myStack<U> &theStack);

protected:
    void nukem();

private:
    void copy(const myStack &other);
    void makeCopy(node *ptr);

};

template<typename U>
std::ostream &operator<<(std::ostream &out, const myStack<U> &theStack) {
//    return <a#initializer#>;
}

template<typename U>
std::istream &operator>>(std::istream &in, myStack<U> &theStack) {
//    return <#initializer#>;
}

template<typename T>
myStack<T>::myStack(int cap) : baseStack(cap){ // This initializes a baseStack with (cap), which resizes it
//    bool debug = true;
//    if (debug)
//        std::cout << "\nmyStack created\n";
}

template<typename T>
myStack<T>::~myStack() {
    while(!isEmpty())
        nukem();
}

template<typename T>
myStack<T>::myStack(const myStack<T> &other) {

}

template<typename T>
myStack<T> &myStack<T>::operator=(const myStack<T> &other) {
//    return <#initializer#>;
}

template<typename T>
T myStack<T>::pop() {
    try {
//        baseStack::pop();
        return *(static_cast<T*>(baseStack::pop()->access()));
    }
    catch (BASESTACK_ERRORS e)
    {
        std::cout << "Stack is empty!! Cannot pop data" << std::endl;
    }
    catch (...)
    {
        std::cout << "An unknown error has occured. Program terminating" << std::endl;
        exit(1);
    }
}

template<typename T>
void myStack<T>::push(const T &data) {

    try
    {
        myNode<T> *newNode = new myNode<T>(data);
        baseStack::push(newNode);
    }
    catch(BASESTACK_ERRORS e)
    {
        std::cout<<"Stack full!! Cannot push data!"<<std::endl;
    }
    catch(...)
    {
        std::cout<<"An unknown error occurred. Program terminating."<<std::endl;
        exit(1);
    }
}

template<typename T>
T myStack<T>::top()
{
    try
    {
        return *(static_cast<T*>(baseStack::top()->access()));
    }
    catch(BASESTACK_ERRORS e)
    {
        std::cout<<"Stack empty!! Cannot pop data!"<<std::endl;
    }
    catch(...)
    {
        std::cout<<"An unknown error occurred. Program terminating."<<std::endl;
        exit(1);
    }
}

template<typename T>
void myStack<T>::nukem()
{
    delete static_cast<T*>(baseStack::top()->access());
    baseStack::pop();
}

template<typename T>
void myStack<T>::copy(const myStack& other)
{
    try
    {
        node* ptr = other->top();
        makeCopy(ptr);
    }
    catch (BASESTACK_ERRORS e)
    {

    }
}

template<typename T>
void myStack<T>::makeCopy(node* ptr)
{
    if(!ptr)
        makeCopy(ptr->getNext());
    push(*(static_cast<T*>(ptr->access())));
}

}


#endif //CS008_MYSTACK_H
