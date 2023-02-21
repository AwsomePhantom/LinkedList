
/*
 *
 *  Name: Rabinul Islam
 *  ID: 011213010
 *  Course Name: Data Structure And Algorithms Lab
 *  Course Code: CSE 2216
 *  Section: B
 *
 */

#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <bits/stdc++.h>
#include "snode.h"

template <class T>
class CircularList
{
private:
    SNODE<T> *head;
    SNODE<T> *tail;
    std::size_t length;

    bool IndexValid(int index);
    SNODE<T>* getLastNode();
public:
    CircularList();
    CircularList(T);
    T At(int index);
    void Insert(T value);
    void InsertAt(T value, int index);
    void InsertFront(T value);
    void Remove(T value);
    void RemoveAt(int index);

    std::size_t GetLength() const;
    std::size_t GetLength();

    void PrintList();
};

#endif // CIRCULARLIST_H
