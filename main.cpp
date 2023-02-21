
#include <bits/stdc++.h>
#include "doublelist.cpp"
#include "circularlist.cpp"

using namespace std;

void separator() {
    for(int i = 0; i < 80; i++) {
        cout << "-";
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));

    DoubleList<int> doubleList;
    CircularList<int> circularList;

    for(int i = 0; i < 10; i++) {
        doubleList.Insert(1 + rand() % 100);
        circularList.Insert(1 + rand() % 100);
    }

    separator();
    cout << "Double Linked List" << endl;
    separator();

    doubleList.PrintList();

    separator();
    cout << "Elements insertions (100 to the front, 200 to the end, 555 at index 3)" << endl;
    separator();
    doubleList.InsertHead(100);
    doubleList.InsertTail(200);
    doubleList.InsertAt(555, 3);
    doubleList.PrintList();

    separator();
    cout << "Elements eliminations (555, at index 2)" << endl;
    separator();
    doubleList.Remove(555);
    doubleList.RemoveAt(2);
    doubleList.PrintList();

    separator();
    cout << "Reverse" << endl;
    separator();
    doubleList.Reverse();
    doubleList.PrintList();

    separator();
    cout << "Circular Linked List" << endl;
    separator();
    circularList.PrintList();

    separator();
    cout << "Elements insertions (100 to the end, 200 at index 5, 400 to the front)" << endl;
    separator();
    circularList.Insert(100);
    circularList.InsertAt(200, 5);
    circularList.InsertFront(400);
    circularList.PrintList();

    separator();
    cout << "Elements eliminations (100, at index 2)" << endl;
    separator();
    circularList.Remove(100);
    circularList.RemoveAt(2);
    circularList.PrintList();

    return 0;
}
