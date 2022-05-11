/*----------------- BankList.h --------------------------------------

    This file contains the declaration of the class BankList which
    implements a linked list data type

    Basic operations:
        constructor - creates a list object, sets root to null
        destructor - deallocates memory for all nodes in the list
        reset - remove all the nodes in the list
        append - adds a node to the end of the list
        remove - removes a specified node from the list
        search - returns true if a specified node is in the list
        isEmpty - returns true if the list is empty
        display - print the list from root to tail

-------------------------------------------------------------------*/
 
#ifndef BANKLIST_H
#define BANKLIST_H

#include <iostream>
#include <string>
using namespace std;
class BankList
{
    public:

    //-------------------- Public Member Functions ------------------
        BankList();
        /*-----------------------------------------------------------
         Construct a BankList object

         Precondition:  None.
         Postcondition: An empty BankList has been constructed.
        -----------------------------------------------------------*/

        ~BankList();
        /*-----------------------------------------------------------
         Destructor.

         Precondition:  The BankList object exists.
         Postcondition: All nodes in the list have been deallocated.
        -----------------------------------------------------------*/

        void reset();
        /*-----------------------------------------------------------
         Remove all nodes in the list.

         Precondition: The BankList object exists.
         Postcondition: All nodes in the list are removed. The
                        head and tail are set to null.
        -----------------------------------------------------------*/

        void append(string newData);
        /*-----------------------------------------------------------
         Append a node to the list.

         Precondition: The BankList object exists.
         Postcondition: A new node has been added to the list.
        -----------------------------------------------------------*/

        void remove(string removeData);
        /*-----------------------------------------------------------
         Remove a node to the list.

         Precondition: The BankList is not empty.
         Postcondition: The specified node has been removed.
        -----------------------------------------------------------*/

        bool search(string searchData);
        /*-----------------------------------------------------------
         Search for a node in the list.

         Precondition: The BankList object exists.
         Postcondition: Return true if the specified node is in the
                        list, return false otherwise.
        -----------------------------------------------------------*/

        bool isEmpty();
        /*-----------------------------------------------------------
         Determine if the list is empty.

         Precondition: The BankList object exists.
         Postcondition: Return true if the list is empty, otherwise
                        return false.
        -----------------------------------------------------------*/

        void display();
        /*-----------------------------------------------------------
         Display the list.

         Precondition: The BankList object exists.
         Postcondition: The list is printed from head to tail.
        -----------------------------------------------------------*/

    private:

    //------------------ Data Members -------------------------------

    // definition for listNode class
    class ListNode
    {
        public:
            string data;
            ListNode *next;
            // constructor - set data
            ListNode(string str) : data(str), next(nullptr) {}
    };

    ListNode *head;
    ListNode *tail;
};

#endif