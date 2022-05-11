/**
 * @file BankList.cpp
 * @author Robert McKay
 * @brief Implementation file for BankList.
 * @version 0.1
 * @date 2022-05-11
 * 
 */

#include "BankList.h"

BankList::BankList()
{
    head = nullptr;
    tail = nullptr;
}

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

void BankList::append(string value)
{
    ListNode *newNode;
    newNode = new ListNode(value);
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

void BankList::remove(string target)
{
    ListNode *nodePtr, *previousNode;
    if (!head)
    {
        return;
    }
    if (head->data == target)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;
        while (nodePtr && nodePtr->data != target)
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

bool BankList::search(string target)
{
    ListNode *nodePtr = head;
    while (nodePtr)
    {
        if (nodePtr->data == target)
        {
            return true;
        }
        nodePtr = nodePtr->next;
    }
    return false;
}

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