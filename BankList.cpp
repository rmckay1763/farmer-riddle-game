/*----------- BankList.cpp ------------------------------------------

   This file implements the member functions for the ADT BankList

-------------------------------------------------------------------*/

#include "BankList.h"

// definition for constructor
BankList::BankList()
{
    head = nullptr;
    tail = nullptr;
}

// definition for destructor
BankList::~BankList()
{
    ListNode *nodePtr, *nextNode;
    nodePtr = head;
    while (nodePtr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

// defintion for the member function reset()
void BankList::reset()
{
    ListNode *nodePtr, *nextNode;
    nodePtr = head;
    while (nodePtr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

// definition for the member function append
void BankList::append(string newData)
{
    ListNode *newNode;
    newNode = new ListNode(newData);
    if (!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// definition for the member function remove
void BankList::remove(string removeData)
{
    ListNode *nodePtr, *previousNode;
    if (!head)
    {
        return;
    }
    if (head->data == removeData)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;
        while (nodePtr && nodePtr->data != removeData)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            if (nodePtr == tail)
            {
                tail = previousNode;
            }
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

// definition for the member function search
bool BankList::search(string searchData)
{
    ListNode *nodePtr = head;
    while (nodePtr)
    {
        if (nodePtr->data == searchData)
        {
            return true;
        }
        nodePtr = nodePtr->next;
    }
    return false;
}

// definition for the member function isEmpty
bool BankList::isEmpty()
{
    if (!head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// definition for the member function display()
void BankList::display()
{
    ListNode *nodePtr = head;
    if (!nodePtr)
    {
        cout << "<Empty>\n";
    }
    else
    {
        while(nodePtr)
        {
            cout << nodePtr->data << endl;
            nodePtr = nodePtr->next;
        }
    }
}