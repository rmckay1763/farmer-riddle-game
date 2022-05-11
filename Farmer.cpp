/**
 * @file Farmer.cpp
 * @author Robert McKay
 * @brief Implementation file for the Farmer object.
 * @version 0.1
 * @date 2022-05-11
 * 
 */

#include "Farmer.h"

Farmer::Farmer()
{
    onSouthBank = true;
}

void Farmer::reset()
{
    onSouthBank = true;
}

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