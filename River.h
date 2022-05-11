/**
 * @file River.h
 * @author Robert McKay
 * @brief Represents the river in the Farmer Riddle game.
 * @version 0.1
 * @date 2022-05-11
 * 
 */

#ifndef RIVER_H
#define RIVER_H

#include "BankList.h"

/**
 * @brief Represents a river with a north and a south bank. 
 * A BankList object maintains the items on each bank.
 * 
 */
class River
{
    public:

        /**
         * @brief Construct a new River object
         * 
         */
        River();

        /**
         * @brief Reset to initial state (both banks are empty).
         * 
         */
        void reset();

        /**
         * @brief Get the SouthBank object of the river.
         * 
         * @return BankList* Pointer to the SouthBank list.
         */
        BankList* getSouthBank();

        /**
         * @brief Get the NorthBank object of the river.
         * 
         * @return BankList* Pointer to the NorthBank list.
         */
        BankList* getNorthBank();

        /**
         * @brief Display the items in the NorthBank and SouthBank.
         * 
         */
        void display();

        /**
         * @brief Move item from one BankList to the other.
         * 
         * @param onSouthBank If the farmer is on the south bank of the river.
         * @param item The item to move to the other bank.
         */
        void moveItemAcross(bool onSouthBank, string item);

    private:
        /**
         * @brief BankList List of items on the south bank of river.
         * 
         */
        BankList southBank;

        /**
         * @brief BankList List of items on the north bank of river.
         * 
         */
        BankList northBank;
};

#endif