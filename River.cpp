/*----------- River.cpp ------------------------------------------

   This file implements the member functions for the ADT River

-------------------------------------------------------------------*/

#include "River.h"

// definition for the constructor
River::River()
{
    southBank.append("fox");
    southBank.append("chicken");
    southBank.append("grain");
}

// definition for the member function reset
void River::reset()
{
    southBank.reset();
    northBank.reset();
    southBank.append("fox");
    southBank.append("chicken");
    southBank.append("grain");
}

// defintion for the member function getSouthBank
BankList* River::getSouthBank()
{
    return &southBank;
}

// defintion for the member function getNorthBank
BankList* River::getNorthBank()
{
    return &northBank;
}

// definition for the member function display
void River::display()
{
    cout << "\nSouth Bank:\n";
    southBank.display();
    cout << "\nNorth Bank:\n";
    northBank.display();
}

// definition for the member function moveItemAcross
void River::moveItemAcross(bool onSouthBank, string item)
{
    if (onSouthBank)
    {
        southBank.remove(item);
        northBank.append(item);
    }
    else
    {
        northBank.remove(item);
        southBank.append(item);
    }
    
}