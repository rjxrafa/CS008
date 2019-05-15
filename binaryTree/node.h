/**
 * This implementation has been adapted from Paul Wilkinson's CS008 lectures.
 *
 * @author      Rafael Betita
 * @modified    2019-05-14
 */

#ifndef CS008_NODE_H
#define CS008_NODE_H

#include <iostream>

namespace binaryTree{

template<typename T>
struct node {
    T data;
    unsigned int count;

    node(const T &d = T(), int c = 0);
    ~node();
    node(const node<T> &other);


    node<T>& operator=(const node<T> &other);
    node<T>& operator^=(node<T> &other); // this is the swap function for nodes to swap values
    node<T>& operator-=(unsigned int c);
    node<T>& operator+=(unsigned int c);


    bool empty() const;
    void set(const T& d, unsigned int c);
    void clear(); // This function clears all values from a node

    // Node-Node comparison operators
    template<typename S>
    friend
    bool operator<(const node<S> &x, const node<S> &y);

    template<typename S>
    friend
    bool operator<=(const node<S> &x, const node<S> &y);

    template<typename S>
    friend
    bool operator>(const node<S> &x, const node<S> &y);

    template<typename S>
    friend
    bool operator>=(const node<S> &x, const node<S> &y);

    // This will check for data match
    template<typename S>
    friend
    bool operator==(const node<S> &x, const node<S> &y);

    // This will check for exact match (data & count)
    template<typename S>
    friend
    bool operator&=(const node<S> &x, const node<S> &y);

    template<typename S>
    friend
    bool operator!=(const node<S> &x, const node<S> &y);

    // Data-Node comparison operators
    template<typename S>
    friend
    bool operator<(const S &x, const node<S> &y);

    template<typename S>
    friend
    bool operator<=(const S &x, const node<S> &y);

    template<typename S>
    friend
    bool operator>(const S &x, const node<S> &y);

    template<typename S>
    friend
    bool operator>=(const S &x, const node<S> &y);

    template<typename S>
    friend
    bool operator==(const S &x, const node<S> &y);

    template<typename S>
    friend
    bool operator!=(const S &x, const node<S> &y);

    // Node-Data comparison operators
    template<typename S>
    friend
    bool operator<(const node<S> &x, const S &y);

    template<typename S>
    friend
    bool operator<=(const node<S> &x, const S &y);

    template<typename S>
    friend
    bool operator>(const node<S> &x, const S &y);

    template<typename S>
    friend
    bool operator>=(const node<S> &x, const S &y);

    template<typename S>
    friend
    bool operator==(const node<S> &x, const S &y);

    template<typename S>
    friend
    bool operator!=(const node<S> &x, const S &y);

    template<typename S>
    friend
    bool operator-=(const node<S> &x, unsigned int c);

    template<typename S>
    friend
    bool operator+=(const node<S> &x, unsigned int c);

    template<typename S>
    friend
    std::ostream& operator<<(std::ostream& out, const node<S> &n);

    template<typename S>
    friend
    std::istream& operator>>(std::istream& in, const node<S> &n);


private:
    void copy(const node<T> &other);
};

template<typename T>
node<T>::node(const T &d, int c) {
    set(d,c);
}

template<typename T>
node<T>::~node() {
    clear();
}

template<typename T>
node<T>::node(const node<T> &other) {
    copy(other);
}

template<typename T>
node<T> &node<T>::operator=(const node<T> &other) {
    if (this != &other)
        copy(other);
    return *this;
}

/**
 * This function swaps the values of two nodes
 * @tparam T
 * @param other
 * @return
 */
template<typename T>
node<T> &node<T>::operator^=(node<T> &other) {
    T temp = data;
    data = other.data;
    other.data = temp;

    // XOR Swap for ints
    other.count ^= count ^=other.count ^= count;
    return *this;
}

template<typename T>
node<T> &node<T>::operator-=(unsigned int c) {
// if c is greater than current count, then set count to 0, otherwise, subtract c from count
    count = (c>=count) ? 0 : count - c;
    return *this;
}

template<typename T>
node<T> &node<T>::operator+=(unsigned int c) {
    count += c;
    return *this;
}

template<typename T>
bool node<T>::empty() const {
    return count == 0;
}

template<typename T>
void node<T>::set(const T &d, unsigned int c) {
    data = d;
    count = c;
}

template<typename T>
void node<T>::clear() {
    set(T(), 0);
}

template<typename T>
void node<T>::copy(const node<T> &other) {
    set(other.data, other.count);
}

template<typename S>
bool operator<(const node<S> &x, const node<S> &y) {
    return 0;
}

template<typename S>
bool operator<=(const node<S> &x, const node<S> &y) {
    return 0;
}

template<typename S>
bool operator>(const node<S> &x, const node<S> &y) {
    return 0;
}

template<typename S>
bool operator>=(const node<S> &x, const node<S> &y) {
    return 0;
}

template<typename S>
bool operator==(const node<S> &x, const node<S> &y) {
    return 0;
}

template<typename S>
bool operator&=(const node<S> &x, const node<S> &y) {
    return 0;
}

template<typename S>
bool operator!=(const node<S> &x, const node<S> &y) {
    return 0;
}

template<typename S>
bool operator<(const S &x, const node<S> &y) {
    return 0;
}

template<typename S>
bool operator<=(const S &x, const node<S> &y) {
    return 0;
}

template<typename S>
bool operator>(const S &x, const node<S> &y) {
    return 0;
}

template<typename S>
bool operator>=(const S &x, const node<S> &y) {
    return 0;
}

template<typename S>
bool operator==(const S &x, const node<S> &y) {
    return 0;
}

template<typename S>
bool operator!=(const S &x, const node<S> &y) {
    return 0;
}

template<typename S>
bool operator<(const node<S> &x, const S &y) {
    return 0;
}

template<typename S>
bool operator<=(const node<S> &x, const S &y) {
    return 0;
}

template<typename S>
bool operator>(const node<S> &x, const S &y) {
    return 0;
}

template<typename S>
bool operator>=(const node<S> &x, const S &y) {
    return 0;
}

template<typename S>
bool operator==(const node<S> &x, const S &y) {
    return 0;
}

template<typename S>
bool operator!=(const node<S> &x, const S &y) {
    return 0;
}

template<typename S>
bool operator-=(const node<S> &x, unsigned int c) {
    return 0;
}

template<typename S>
bool operator+=(const node<S> &x, unsigned int c) {
    return 0;
}

template<typename S>
std::ostream &operator<<(std::ostream &out, const node<S> &n) {
    return <#initializer#>;
}

template<typename S>
std::istream &operator>>(std::istream &in, const node<S> &n) {
    return <#initializer#>;
}

}


#endif //CS008_NODE_H
