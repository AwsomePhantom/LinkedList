
#ifndef SNODE_H
#define SNODE_H

#include <ostream>

template <class T>
class SNODE
{
public:
    T data;
    SNODE<T> *next;
    SNODE() {
        this->next = nullptr;
    }
    SNODE(T val) {
        this->data = val;
        this->next = nullptr;
    }
    friend std::ostream& operator<<(std::ostream& os, SNODE<T>& n) {
        os << n.data;
        return os;
    }
};

#endif // SNODE_H
