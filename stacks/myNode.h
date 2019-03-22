//
// Created by rafab on 3/21/2019.
//

#ifndef CS008_MYNODE_H
#define CS008_MYNODE_H

#include <iostream>
#include "node.h"

namespace stacks {

template<typename T>
class myNode : public node {
public:
    myNode(const T &data = T());
    ~myNode() override;
    myNode(const myNode<T> &other);
    myNode<T> &operator=(const myNode<T> &other);

    void modifyData (void *d) override;

protected:
    void makeCopy(const node &other) override;

private:

};

template<typename T>
stacks::myNode<T>::myNode(const T &data) {

    void *ptr = new T(data);
//    modifyData(ptr);
    setData(ptr);
}


template<typename T>
stacks::myNode<T>::~myNode() {
    bool debug = true;
    if (debug)
        std::cout << "\nmyNode destructor called\n";
}

template<typename T>
stacks::myNode<T>::myNode(const stacks::myNode<T> &other) {


}

template<typename T>
stacks::myNode<T> &stacks::myNode<T>::operator=(const stacks::myNode<T> &other) {
//    if (this != &other)
//        node::access() = new T(*static_cast<T>(other.access()));
    return *this;

}

//template<typename T>
//void stacks::myNode<T>::makeCopy(const stacks::node *n) {
//    node::access() = new T(*(T*)(n->access()));
//    1;
//}

template<typename T>
void myNode<T>::modifyData(void *d) {
    setData(d);
}

template<typename T>
void stacks::myNode<T>::makeCopy(const stacks::node &other) {

}

}








#endif //CS008_MYNODE_H
