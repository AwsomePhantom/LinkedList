
#include "circularlist.h"

template <class T>
CircularList<T>::CircularList()
{
    length = 0;
}

template <class T>
CircularList<T>::CircularList(T val) {
    SNODE<T> *node = new SNODE<T>(val);
    head = node;
    head->next = head;
    tail = head;
    length = 1;
}

template <class T>
bool CircularList<T>::IndexValid(int index) {
    if(index < 0 || index > length - 1) {
        std::cout << "Index out of bound." << std::endl;
        return false;
    }
    return true;
}

template <class T>
T CircularList<T>::At(int index) {
    if(!IndexValid(index)) return -1;

    if(index == 0) {
        return head->data;
    }
    else if(index == length - 1) {
        return tail->data;
    }
    else {
        SNODE<T> *it = head->next;
        std::size_t count = 1;

        while(it != head && count != index) {
            it = it->next;
            count++;
        }

        return it->data;
    }
}

template <class T>
SNODE<T>* CircularList<T>::getLastNode() {
    SNODE<T> *it = head;
    while(it->next != head) {
        it = it->next;
    }
    tail = it;
    return it;
}

template <class T>
void CircularList<T>::Insert(T val) {
    SNODE<T> *node = new SNODE<T>(val);
    if(head == nullptr) {
        head = node;
        head->next = head;
        tail = head;
        length = 1;
    }
    else {
        getLastNode();

        tail->next = node;
        node->next = head;
        length++;
    }
}

template <class T>
void CircularList<T>::InsertAt(T val, int index) {
    if(index < 0 || index > length) {
        std::cout << "Index out of bound." << std::endl;
        return;
    }

    if(index == 0) InsertFront(val);
    else if(index == length) Insert(val);
    else {
        SNODE<T> *node = new SNODE<T>(val);

        SNODE<T> *prevPtr = head;
        SNODE<T> *currPtr = head->next;
        std::size_t count = 1;

        while(currPtr != head && count < index) {
            prevPtr = currPtr;
            currPtr = currPtr->next;
            count++;
        }

        if(count == index) {
            prevPtr->next = node;
            node->next = currPtr;
            length++;
        }
    }
}

template <class T>
void CircularList<T>::InsertFront(T val) {
    SNODE<T> *node = new SNODE<T>(val);
    getLastNode();

    tail->next = node;
    node->next = head;
    head = node;
    length++;
}

template <class T>
void CircularList<T>::Remove(T val) {
    if(head == nullptr) {
        std::cout << "List empty!" << std::endl;
        return;
    }

    if(head->data == val) {
        SNODE<T> *temp = head;

        head = head->next;
        if(head == nullptr) {
            head = tail = nullptr;
        }
        else {
            tail->next = head;
        }
        delete temp;
        length--;
    }
    else {

        SNODE<T> *prevPtr = head;
        SNODE<T> *currPtr = head->next;

        while(currPtr != head && currPtr->data != val) {
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }
        if(currPtr != head) {
            SNODE<T> *temp = currPtr;
            prevPtr->next = currPtr->next;
            if(currPtr->next == head) {
                tail = prevPtr;
            }
            delete temp;
            length--;
        }
    }
}

template <class T>
void CircularList<T>::RemoveAt(int index) {
    if(!IndexValid(index)) return;

    if(index == 0) {
        SNODE<T> *temp = head;

        head = head->next;
        tail->next = head;
        delete temp;
        length--;
    }
    else {
        SNODE<T> *prevPtr = head;
        SNODE<T> *currPtr = head->next;
        std::size_t count = 1;

        while(currPtr != head && count < index) {
            prevPtr = currPtr;
            currPtr = currPtr->next;
            count++;
        }
        if(count == index) {
            SNODE<T> *temp = currPtr;
            prevPtr->next = currPtr->next;
            if(currPtr->next == head) {
                tail = prevPtr;
            }
            delete temp;
            length--;
        }
    }
}

template <class T>
std::size_t CircularList<T>::GetLength() const {
    return length;
}

template <class T>
std::size_t CircularList<T>::GetLength() {
    if(head == nullptr) return 0;

    SNODE<T> *it = head;
    std::size_t count = 0;

    while(it != tail && ++count) {
        it = it->next;
    }
    return ++count;
}

template <class T>
void CircularList<T>::PrintList() {
    if(head == nullptr) {
        std::cout << "List empty!" << std::endl;
    }
    else {
        SNODE<T> *it = head;

        do {
            std::cout << *it << " -> ";
            it = it->next;
        }
        while(it != head);
        std::cout << std::endl;
        std::cout << "Size: " << length << std::endl;
    }
}
