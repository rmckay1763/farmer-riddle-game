/**
 * @file Farmer.h
 * @author Robert McKay
 * @brief Represents the farmer in the Farmer Riddle game.
 * @version 0.1
 * @date 2022-05-11
 * 
 */

#ifndef FARMER_H
#define FARMER_H

#include "River.h"

/**
 * @brief The farmer in the Farmer Riddle game. Keeps track of which side of
 * the river the farmer is on and checks for won/lost state.
 * 
 */
class Farmer
{
    public:

        /**
         * @brief Construct a new Farmer object
         * 
         */
        Farmer();

        /**
         * @brief Reset onSouthBank to true.
         * 
         */
        void reset();

        /**
         * @brief Display the side of the river the farmer is on.
         * 
         */
        void display();
        
        /**
         * @brief Check the won/lost conditions of the Farmer Riddle game.
         * 
         * @param river River object with list of items on each bank.
         * @return true If all items accross river or chicken and fox on same side.
         */
        bool hasWonLost(River *river);
        
        /**
         * @brief Execute a trip across the river.
         * 
         * @param river River object with list of items on each bank.
         */
        void crossRiver(River *river);
        
    private:

        /**
         * @brief Determine which item the farmer will take across the river.
         * 
         * @param river River object with list of items on each bank.
         * @return string The item to take across [chicken, fox, grain, nothing].
         */
        string getDecision(River *river);
        
        /**
         * @brief Prompt the user for an item to take across the river.
         * 
         * @param bank BankList of items for the bank the farmer is currently on.
         * @return string The item to move to the other BankList.
         */
        string getDecisionAux(BankList *bank);
        
        /**
         * @brief Check the BankList for conflict conditions.
         * 
         * @param bank BankList of items on one side of the River.
         * @return true If the BankList contains a conflict.
         */
        bool isConflict(BankList *bank);

        /**
         * @brief Boolean flag to track which bank the farmer is on.
         * 
         */
        bool onSouthBank;
};

#endif