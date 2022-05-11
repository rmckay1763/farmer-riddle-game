/**
 * @file BankList.h
 * @author Robert McKay
 * @brief Singly linked list of strings for use with the Farmer Riddle game.
 * @version 0.1
 * @date 2022-05-10
 * 
 */
 
#ifndef BANKLIST_H
#define BANKLIST_H

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Singly linked list of strings with inner node class. 
 * 
 */
class BankList
{
    public:

        /**
         * @brief Construct a new BankList object.
         * 
         */
        BankList();

        /**
         * @brief Destroy the Bank List object.
         * 
         */
        ~BankList();

        /**
         * @brief Remove all nodes in the list.
         * 
         */
        void reset();

        /**
         * @brief Append a new node to the list.
         * 
         * @param value Data to append to list
         */
        void append(string value);

        /**
         * @brief Remove a node from the list with matching data.
         * 
         * @param target The data of the node to remove.
         */
        void remove(string target);

        /**
         * @brief Search if the list contains a node with a specified value.
         * 
         * @param target The value to search for.
         * @return true If the list contains the value, false otherwise.
         */
        bool search(string target);

        /**
         * @brief Check if the list is empty.
         * 
         * @return true If the list is empty, false otherwise 
         */
        bool isEmpty();

        /**
         * @brief Print the list to std out
         * 
         */
        void display();

    private:

    /**
     * @brief List node for BankList.
     * 
     */
    class ListNode
    {
        private:
            /**
             * @brief Construct a new List Node object.
             * 
             * @param str Value to store at node.
             */
            ListNode(string str) : data(str), next(nullptr) {}

            string data;
            ListNode *next;
            friend class BankList;
    };

    ListNode *head;
    ListNode *tail;
};

#endif