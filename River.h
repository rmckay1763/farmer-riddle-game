/*----------------- River.h ----------------------------------------

    This file contains the declaration of the ADT River.

    Basic operations:
        constructor - create a River object and populate southBank
        reset - reset the River to its initial state
        getSouthBank - return a pointer to the data member southBank
        getNorthBank - return a pointer to the data member northBank
        display - display the items in each BankList
        moveItemAcross - swaps specified item to opposite bank

-------------------------------------------------------------------*/

#ifndef RIVER_H
#define RIVER_H

#include "BankList.h"

class River
{
    public:

    //-------------------- Public Member Functions ------------------
        /**
         * @brief Construct a new River object
         * 
         */
        River();
        /*-----------------------------------------------------------
         Construct a River object

         Precondition:  None.
         Postcondition: southBank is populated, northBank is empty.
        -----------------------------------------------------------*/

        void reset();
        /*-----------------------------------------------------------
         Reset the River object to its initial state

         Precondition:  The river object exists.
         Postcondition: southBank is populated, northBank is empty.
        -----------------------------------------------------------*/

        BankList* getSouthBank();
        /*-----------------------------------------------------------
         Return a pointer to the data member southBank

         Precondition:  The river object exists.
         Postcondition: A pointer to southBank is returned.
        -----------------------------------------------------------*/

        BankList* getNorthBank();
        /*-----------------------------------------------------------
         Return a pointer to the data member northBank

         Precondition:  The river object exists.
         Postcondition: A pointer to northBank is returned.
        -----------------------------------------------------------*/

        void display();
        /*-----------------------------------------------------------
         Display the items in each BankList data member

         Precondition:  The river object exists.
         Postcondition: The items on each bank are displayed.
        -----------------------------------------------------------*/

        void moveItemAcross(bool onSouthBank, string item);
        /*-----------------------------------------------------------
         Swap specified item to other BankList data member

         Precondition: The item to be swapped is specified.
         Postcondition: The specified item is in the other BankList.
        -----------------------------------------------------------*/

    private:
        BankList southBank;
        BankList northBank;
};

#endif