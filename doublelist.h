
/*
 *
 *  Name: Rabinul Islam
 *  ID: 011213010
 *  Course Name: Data Structure And Algorithms Lab
 *  Course Code: CSE 2216
 *  Section: B
 *
 */

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <bits/stdc++.h>
#include "dnode.h"

template <class T>
class DoubleList {
private:
    DNODE<T> *head;
    std::size_t length;

    bool IndexValid(int index);
public:
    DoubleList();
    DoubleList(T value);
    T At(int index);
    void Insert(T value);
    void InsertHead(T value);
    void InsertTail(T value);
    void InsertAt(T value, int index);
    T Remove(T value);
    void RemoveAt(int index);
    void Reverse();

    std::size_t GetLength() const;
    std::size_t GetLength();


    void PrintList();
};

#endif // DOUBLELIST_H
