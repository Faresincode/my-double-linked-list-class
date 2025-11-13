//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#pragma once
#include <iostream>
using namespace std;


template <class T>
class clsDblLinkedList
{
private:


    unsigned int _Size = 0;

public:

    class Node
    {

    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    bool IsEmpty()
    {
        return ((_Size==0)?true:false);
    }

    void InsertAtBeginning(T value)
    {
            //1-Create a new node with the desired value.
            //2-Set the next pointer of the new node to the current head of the list.
            //3-Set the previous pointer of the current head to the new node.
            //4-Set the new node as the new head of the list.
        
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        _Size++;

    }

    // Print the linked list
    void PrintList()
    {
        if (head == nullptr)
        {
            return;
        }
        Node* Current = head;

        while (Current != NULL) {
            cout << Current->value << " ";
            Current = Current->next;
        }
        cout << "\n";


    }

    Node* Find(T Value)
    {
        Node* Current = head;
        while (Current != NULL) {

            if (Current->value == Value)
                return Current;

            Current = Current->next;
        }

        return NULL;

    }

    void InsertAfter(Node* current, T value) {


         //1 - Create a new node with the desired value.
         //    2-Set the next pointer of the new node to the next node of the current node.
         //    3-Set the previous pointer of the new node to the current node.
         //    4-Set the next pointer of the current node to the new node.
         //    5-Set the previous pointer of the next node to the new node(if it exists).
        

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) 
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
        _Size++;


    }

    void InsertAtEnd(T value)
    {
            //1-Create a new node with the desired value.
            //2-Traverse the list to find the last node.
            //3-Set the next pointer of the last node to the new node.
            //4-Set the previous pointer of the new node to the last node.
       
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL) 
        {
            newNode->prev = NULL;
            head = newNode;
        }
        else 
        {
            Node* current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        _Size++;


    }

    void DeleteNode(Node*& NodeToDelete) {

        
           //1-Set the next pointer of the previous node to the next pointer of the current node.
           // 2-Set the previous pointer of the next node to the previous pointer of the current node.
           // 3-Delete the current node.
        
        if (head == NULL || NodeToDelete == NULL)
        {
            return;
        }
        if (head == NodeToDelete) 
        {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL)
        {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) 
        {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        delete NodeToDelete;
        _Size--;


    }

    void DeleteFirstNode()
    {

        
            //1-Store a reference to the head node in a temporary variable.
            //2-Update the head pointer to point to the next node in the list.
            //3-Set the previous pointer of the new head to NULL.
            //4-Delete the temporary reference to the old head node.
        

        if (head == NULL) 
        {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
        _Size--;

    }

    void DeleteLastNode()
    {

        
            //1-Traverse the list to find the last node.
            //2-Set the next pointer of the second-to-last node to NULL.
            //3-Delete the last node.
       

        if (head == NULL) 
        {
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        // we need to find the node before last node.
        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        _Size--;

    }

    void PrintNodeDetails(Node* Current)
    {

        if (Current->prev != NULL)
            cout << Current->prev->value;
        else
            cout << "NULL";

        cout << " <--> " << Current->value << " <--> ";

        if (Current->next != NULL)
            cout << Current->next->value << "\n";
        else
            cout << "NULL";

    }

    void DeleteNodeByValue(T value)
    {

        if (head == nullptr)
        {
            return;
        }

        Node* NodeToDelete = Find(value);
        if (NodeToDelete == nullptr)
        {
            return;
        }
        else
        {

            if (NodeToDelete->next != nullptr)
            {
                NodeToDelete->next->prev = NodeToDelete->prev;

            }
            if (NodeToDelete->prev != nullptr)
            {
                NodeToDelete->prev->next = NodeToDelete->next;

            }

        } 
       
        delete NodeToDelete;
        _Size--;

    }


    void ReverseList()
    {

        if (head == nullptr)
        {
            return;
        }
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr)
        {
            temp = current->prev;          // save current->prev temporarily
            current->prev = current->next;  // swap prev and next
            current->next = temp;

            current = current->prev;        // move to next node (which is previous before swap)
        }

        if (temp != nullptr)
            head = temp->prev;              // update head to last node processed
    }

    void ToCircularLinkedList()
    {
        if (head == nullptr)
            return;

        Node* tail = head;

        // find last node
        while (tail->next != nullptr)
            tail = tail->next;

        // connect head and tail to make circular
        tail->next = head;
        head->prev = tail;
    }

    void BackToNormalLinkedList()
    {
        if (head == nullptr)
            return;

        Node* tail = head;

        // find last node
        while (tail->next != head)
            tail = tail->next;

        // connect head and tail to make circular
        tail->next = nullptr;
        head->prev = nullptr;
    }



    void PrintListDetails()

    {
        cout << "\n\n";
        Node* Current = head;
        while (Current != NULL)
        {
            PrintNodeDetails(Current);
            Current = Current->next;
        }
    }


    int Size()
    {
        return _Size;
    }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    void Swap(Node*& Prev, Node*& Next)
    {
        Node* Temp = Prev;
        Prev = Next;
        Next = Temp;

    }

    void Reverse()
    {

        if (head == nullptr)
        {
            return;
        }

        Node* Current = head;
        Node* Temp = nullptr;
   
        while (Current != nullptr)
        {
            Temp = Current->prev;
            Swap(Current->prev, Current->next);

            Current = Current->prev;
        }
        if (Temp != nullptr)
        {
            head = Temp->prev;
        }


    }

    Node* GetNode(int Index)
    {

        int Counter = 0;
        if (Index > _Size - 1 || Index < 0)
            return NULL;
        Node* Current = head;
        while (Current != NULL && (Current->next != NULL))
        {
            if (Counter == Index)
                break;
            Current = Current->next;
            Counter++;
        }
        return Current;
    }

    T GetItem(int Index)
    {

        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL)
            return NULL;
        else
            return ItemNode->value;

    }

    bool UpdateItem(int ItemIndex, T NewValue)
    {
        Node* ItemNode = GetNode(ItemIndex);
        if (ItemNode != NULL)
        {
            ItemNode->value = NewValue;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool InsertAfter(int ItemIndex, T Value)
    {
        if (ItemIndex > _Size - 1 || ItemIndex < 0)
            return false;
        Node* ItemNode = GetNode(ItemIndex);
        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, Value);
            return true;
        }
        else
        {
            return false;
        }
    }



};
