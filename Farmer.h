/*----------------- Farmer.h ----------------------------------------

    This file contains the declaration of the ADT Farmer.

    Basic operations:
        constructor - creates a Farmer object
        reset - reset the data member onSouthBank to true
        display - displays the location of the farmer
        hasWonLost - return true if a win/loose condition is
            satisfied, return false otherwise. utilizes the
            function isConflict
        crossRiver - execute one trip across the river. utilizes the
            functions getDecision and River::moveItemAcross

    Private functions:
        getDecision - returns a string value for what the farmer
            decides to take accros the river. utilizes the
            auxiliary function getDecisionAux
        getDecisionAux - auxiliary function for getDecision
        isConflict - helper function for checkWinLoose. returns
            true if a conflict exists in a given BankList, return
            false otherwise

-------------------------------------------------------------------*/

#ifndef FARMER_H
#define FARMER_H

#include "River.h"

class Farmer
{
    public:

    //-------------------- Public Member Functions ------------------
        Farmer();
        /*-----------------------------------------------------------
         Construct a Farmer object

         Precondition:  None.
         Postcondition: the data member onSouthBank is set to true.
        -----------------------------------------------------------*/

        /**
         * @brief 
         * 
         */
        void reset();
        /*-----------------------------------------------------------
         Reset a Farmer object

         Precondition:  The Farmer object exists.
         Postcondition: the data member onSouthBank is set to true.
        -----------------------------------------------------------*/

        void display();
        /*-----------------------------------------------------------
         Display the farmer's location

         Precondition:  The Farmer object exists.
         Postcondition: The location of the farmer (north/south bank)
                        is displayed.
        -----------------------------------------------------------*/
        
        bool hasWonLost(River *river);
        /*-----------------------------------------------------------
         Check if the farmer has won/lost at getting everthing
         accros the river.

         Precondition:  The Farmer and the River objects exist.
         Postcondition: True is returned if southBank is empty or
                        if there is a conflict in the list on the
                        opposite bank of the farmer, false is
                        returned otherwise.
         Note: This function utilizes the helper function isConflict
        -----------------------------------------------------------*/
        
        void crossRiver(River *river);
        /*-----------------------------------------------------------
         Execute a trip accros the river

         Precondition:  The Farmer and the River objects exist.
         Postcondition: The farmer and the item he chooses is
                        transfered to the opposite bank
         Note: This function utilizes the two functions getDecision
               and River::moveItemAcross
        -----------------------------------------------------------*/
        
    private:

    //-------------------- Private Member Functions ------------------
        string getDecision(River *river);
        /*-----------------------------------------------------------
         Determine which item to take accros the river

         Precondition:  The Farmer and the River objects exist.
         Postcondition: A string is return containing the farmers
                        decision of which item to take across
        -----------------------------------------------------------*/
        
        string getDecisionAux(BankList *bank);
        /*-----------------------------------------------------------
         Auxiliary function for getDecision

         Precondition:  The correct BankList object is passed.
         Postcondition: A string is return containing the farmers
                        decision of which item to take across
        -----------------------------------------------------------*/
        
        bool isConflict(BankList *bank);
        /*-----------------------------------------------------------
         Determine if a conflict exists

         Precondition:  The correct BankList object is passed
         Postcondition: True is returned if there is a conflict,
                        false is returned otherwise
        -----------------------------------------------------------*/
        
    //------------------ Private Data Members -----------------------
        bool onSouthBank;
};

#endif