clsDblLinkedList - C++ Doubly Linked List Implementation
=====================================================

Overview
--------
`clsDblLinkedList` is a fully-featured, template-based implementation of a **doubly linked list** in C++.
It supports standard linked list operations like insertion, deletion, searching, reversing, and more.
This class is designed for educational and practical use, demonstrating dynamic memory management
and data structure manipulation.

File: clsDblLinkedList.h

-----------------------------------------------------
Features
-----------------------------------------------------
✅ Supports all standard linked list operations  
✅ Template-based design for any data type  
✅ Allows insertion/deletion at any position  
✅ Includes reverse and sorting options  
✅ Easily extensible and readable code  
✅ Proper memory management with destructors  

-----------------------------------------------------
Class Methods Summary
-----------------------------------------------------

**Constructor & Destructor**
- `clsDblLinkedList()` → Initializes an empty list.
- `~clsDblLinkedList()` → Clears all allocated memory.

**Insertion**
- `InsertAtBeginning(T value)` → Inserts a node at the beginning.
- `InsertAtEnd(T value)` → Inserts a node at the end.
- `InsertAfter(int index, T value)` → Inserts a node after a specific index.

**Deletion**
- `DeleteFirstNode()` → Deletes the first node.
- `DeleteLastNode()` → Deletes the last node.
- `DeleteNode(int index)` → Deletes node at given index.
- `DeleteNodeByValue(T value)` → Deletes the first occurrence of a value.
- `Clear()` → Deletes all nodes and resets the list.

**Access**
- `GetItem(int index)` → Returns value at index.
- `Find(T value)` → Returns index of first occurrence of value.
- `IsEmpty()` → Returns true if list is empty.
- `Size()` → Returns total number of nodes.
- `Front()` → Returns first element.
- `Back()` → Returns last element.

**Utilities**
- `UpdateItem(int index, T newValue)` → Updates node value.
- `Reverse()` → Reverses the linked list order.
- `PrintList()` → Displays all elements.

-----------------------------------------------------
Example Usage
-----------------------------------------------------

#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

int main() {
    clsDblLinkedList<int> list;

    list.InsertAtBeginning(3);
    list.InsertAtEnd(5);
    list.InsertAtEnd(7);
    list.InsertAfter(1, 6);

    cout << "List elements: ";
    list.PrintList();

    cout << "Front: " << list.Front() << endl;
    cout << "Back: " << list.Back() << endl;
    cout << "Size: " << list.Size() << endl;

    list.Reverse();
    cout << "Reversed list: ";
    list.PrintList();

    list.DeleteFirstNode();
    list.DeleteLastNode();

    cout << "After deletions: ";
    list.PrintList();

    list.Clear();
    cout << "List cleared. Is empty? " << list.IsEmpty() << endl;

    return 0;
}

-----------------------------------------------------
Expected Output
-----------------------------------------------------
List elements: 3 5 6 7  
Front: 3  
Back: 7  
Size: 4  
Reversed list: 7 6 5 3  
After deletions: 6 5  
List cleared. Is empty? 1  

-----------------------------------------------------
Future Extension Ideas
-----------------------------------------------------
1. Add sorting algorithms (bubble, insertion, merge sort)
2. Add iterator support for range-based loops
3. Add SaveToFile() / LoadFromFile() methods
4. Add Clone() for deep copy functionality
5. Add operator overloading (==, !=, +, etc.)
6. Integrate smart pointers for memory safety
7. Add visualization (Graphviz or console diagram)

-----------------------------------------------------
License
-----------------------------------------------------
📄 License: MIT License  

This project is open-source and can be freely used for educational or personal development.

