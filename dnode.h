
#ifndef DNODE_H
#define DNODE_H

#include <ostream>

template <class T>
class DNODE {
public:
    int data;
    DNODE* next;
    DNODE* prev;
    DNODE() {
        this->next = nullptr;
        this->prev = nullptr;
    }
    DNODE(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    friend std::ostream& operator<<(std::ostream& os, DNODE<T>& n) {
        os << n.data;
        return os;
    }
};

#endif // DNODE_H
