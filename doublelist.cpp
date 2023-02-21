
#include "doublelist.h"

template <class T>
DoubleList<T>::DoubleList() {
    length = 0;
}

template <class T>
DoubleList<T>::DoubleList(T value) {
    DNODE<T> *node = new DNODE(value);
    head = node;
    length = 1;
}

template <class T>
T DoubleList<T>::At(int index) {
    if(!IndexValid(index)) return -1;

    DNODE<T> *it = head;
    std::size_t count = 0;

    while(count != index) {
        it = it->next;
        count++;
    }

    return it->data;
}

template <class T>
bool DoubleList<T>::IndexValid(int index) {
    if(index < 0 || index > length - 1) {
        std::cout << "Index out of bound." << std::endl;
        return false;
    }
    return true;
}

template <class T>
void DoubleList<T>::Insert(T value) {
    InsertTail(value);
}

template <class T>
void DoubleList<T>::InsertHead(T value) {
    DNODE<T> *node = new DNODE<T>(value);

    if(head == nullptr) {
        head = node;
        length = 1;
    }
    else {
        node->next = head;
        head->prev = node;
        head = node;
        length++;
    }
}

template <class T>
void DoubleList<T>::InsertTail(T value) {
    DNODE<T> *node = new DNODE<T>(value);

    if (head == nullptr) {
        head = node;
        length = 1;
    } else {
        DNODE<T> *tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = node;
        node->prev = tail;
        length++;
    }
}

template <class T>
void DoubleList<T>::InsertAt(T val, int index) {
    if(index < 0 || index > length) {
        std::cout << "Index out of bound." << std::endl;
        return;
    }

    if(index == 0) InsertHead(val);
    else if(index == length) InsertTail(val);
    else {
        DNODE<T> *it = head->next;
        std::size_t count = 1;
        while(it != nullptr && count != index) {
            it = it->next;
            count++;
        }
        if(count == index && it != nullptr) {
            DNODE<T> *node = new DNODE<T>(val);
            (it->prev)->next = node;
            node->prev = it->prev;
            node->next = it;
            it->prev = node;
            length++;
        }
    }
}

template <class T>
T DoubleList<T>::Remove(T value) {

    if(head->data == value) {
        DNODE<T> *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        temp = nullptr;
        length--;
        return value;
    }
    else {
        DNODE<T> *prevPtr = nullptr;
        DNODE<T> *currPtr = head;
        while(currPtr != nullptr && currPtr->data != value) {
            prevPtr = currPtr;
            currPtr = currPtr->next;
        }

        if(currPtr != nullptr) {
            DNODE<T> *temp = currPtr;
            prevPtr->next = currPtr->next;
            if(currPtr->next != nullptr) {
                currPtr->next->prev = prevPtr;
            }
            delete temp;
            length--;
            return value;
        }
    }
    return -1;
}

template <class T>
void DoubleList<T>::RemoveAt(int index) {
    if(!IndexValid(index)) return;

    if(index == 0) {
        DNODE<T> *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        length--;
    }
    else {
        DNODE<T> *it = head->next;
        std::size_t count = 1;
        while(it != nullptr && (count++) != index) {
            it = it->next;
        }

        DNODE<T> *temp = it;
        DNODE<T> *prev = it->prev;
        prev->next = it->next;
        if(it->next != nullptr) {
            (it->next)->prev = prev;
        }
        delete temp;
        length--;
    }
}

template <class T>
void DoubleList<T>::Reverse() {
    DNODE<T> *it = head;
    DNODE<T> *temp;
    while(it != nullptr) {
        if(it->next == nullptr) {
            head = it;
        }
        temp = it->next;
        it->next = it->prev;
        it->prev = temp;
        it = it->prev;
    }

    it = head;
    while(it->prev != nullptr) {
        it = it->prev;
    }
    head = it;
}

template <class T>
std::size_t DoubleList<T>::GetLength() const {
    return length;
}


template <class T>
std::size_t DoubleList<T>::GetLength() {
    std::size_t count = 0;
    DNODE<T> *it = head;
    while(it != nullptr && ++count) {
        it = it->next;
    }
    length = count;
    return count;
}

template <class T>
void DoubleList<T>::PrintList() {
    if(head == nullptr) {
        std::cout << "List empty!" << std::endl;
    }
    else {
        DNODE<T> *it = head;
        while (it != nullptr) {
            std::cout << it->data << " -> ";
            it = it->next;
        }
        std::cout << std::endl;
        std::cout << "Size: " << length << std::endl;
    }
}
