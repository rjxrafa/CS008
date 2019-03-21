//
// Created by Rafa on 3/21/2019.
//

#ifndef CS008_NODE_H
#define CS008_NODE_H

namespace stacks {
class node {

public:

    node();
    node(void *ptr);
    virtual ~node() = 0;
    node(const node &other);
    node &operator=(const node &other);

    void *access() const;
    virtual void modifyData(void *d) = 0;

    node *getNext();
    void setNext(node *ptr);

protected:
    virtual void makeCopy(const node &other) = 0;

private:
    void *dataPtr;
    node *next;

    void copy(const node &other);
};

}


#endif //CS008_NODE_H
