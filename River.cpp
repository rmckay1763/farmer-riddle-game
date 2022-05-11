/**
 * @file River.cpp
 * @author Robert McKay
 * @brief Implementation file for River object.
 * @version 0.1
 * @date 2022-05-11
 * 
 */

#include "River.h"

River::River()
{
    southBank.append("fox");
    southBank.append("chicken");
    southBank.append("grain");
}

void River::reset()
{
    southBank.reset();
    northBank.reset();
    southBank.append("fox");
    southBank.append("chicken");
    southBank.append("grain");
}

BankList* River::getSouthBank()
{
    return &southBank;
}

BankList* River::getNorthBank()
{
    return &northBank;
}

void River::display()
{
    cout << "\nSouth Bank:\n";
    southBank.display();
    cout << "\nNorth Bank:\n";
    northBank.display();
}

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