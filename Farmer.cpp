/*----------- Farmer.cpp ------------------------------------------

   This file implements the member functions for the ADT Farmer

-------------------------------------------------------------------*/

#include "Farmer.h"

// definition for the constructor 
Farmer::Farmer()
{
    onSouthBank = true;
}

// definition for the member function reset
void Farmer::reset()
{
    onSouthBank = true;
}

// defintion for the member function display
void Farmer::display()
{
    if (onSouthBank)
    {
        cout << "\nThe farmer is on the south bank.\n";
    }
    else
    {
        cout << "\nThe farmer is on the north bank.\n";
    }
}

// definition for the member function checkWonLost
bool Farmer::hasWonLost(River *river)
{
    bool hasWonLost = false;
    BankList *southBank = river->getSouthBank();
    BankList *northBank = river->getNorthBank();
    if (southBank->isEmpty())
    {
        cout << "\nEverthing is across the river! You won!\n";
        hasWonLost = true;
    }
    if (onSouthBank)
    {
        if (isConflict(northBank))
            hasWonLost = true;
    }
    else
    {
        if (isConflict(southBank))
            hasWonLost = true;
    }
    return hasWonLost;
}

// definition for the member function crossRiver
void Farmer::crossRiver(River *river)
{
    string decision = getDecision(river);
    if (decision == "nothing")
    {
        cout << "\nThe farmer takes nothing with him\n";
    }
    else
    {
        cout << "\nThe farmer takes the ";
        cout << decision << " with him\n";
        river->moveItemAcross(onSouthBank, decision);
    }
    onSouthBank = !onSouthBank;
}

// definition for the private member function getDecision
string Farmer::getDecision(River *river)
{
    string decision;
    BankList *bank;
    if(onSouthBank)
    {
        bank = river->getSouthBank();
    }
    else
    {
        bank = river->getNorthBank();
    }
    decision = getDecisionAux(bank);
    return decision;
}

// definition for the private member function getDecisionAux
string Farmer::getDecisionAux(BankList *bank)
{
    string decision;
    int length;
    while (true)
    {
        cout << "\nWhat should the farmer take with him?: ";
        cin >> decision;
        if (cin.fail())
        {
            cout << "\nInvalid input!\n";
            continue;
        }
        length = decision.length();
        for (int i = 0; i < length; i++)
        {
            decision.at(i) = tolower(decision.at(i));
        }
        if (bank->search(decision) || decision == "nothing")
        {
            return decision;
        }
        else
        {
            cout << "Invalid input!\n";
            cin.ignore(500, '\n');
        }
    }
}

// definition for the private member function isConflict
bool Farmer::isConflict(BankList *bank)
{
    if (bank->search("fox") && bank->search("chicken"))
    {
        cout << "\nThe fox ate the chicken! You lost.\n";
        return true;
    }
    else if (bank->search("chicken") && bank->search("grain"))
    {
        cout << "\nThe chicken ate the grain! You lost.\n";
        return true;
    }
    else
    {
        return false;
    }
}