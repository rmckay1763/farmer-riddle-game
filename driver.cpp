/*----------------- BankList.h --------------------------------------

    Title: Fox, Chicken, Grain Riddle
    Author: Robert McKay
    Date: 08/03/2020
    Purpose:
        This program simulates the classic riddle where a farmer
        has to get a fox, chicken, and grain accross a river
        without leaving the fox with the chicken or leaving the
        chicken with the grain.

    Programmer Defined ADT's:
        BankList - Implements a linked list to keep track of the
                   farmer's items.
        River - Consists of two BankList data members (southBank
                and northBank) and functions to faciliate the
                rules of the game
        Farmer - Uses a boolean to keep track of which bank the 
                 farmer is on. Contains functions that facilitate
                 the rules of the game.

-------------------------------------------------------------------*/

#include "Farmer.h"

int main()
{
    string menu, instructions, horizontalLine(50, '-');
    menu =
        "\nMENU:\n"
        "  i - instructions\n"
        "  p - play game\n"
        "  q - quit game\n"
        "Enter choice [i, p, or q]:\n";
    instructions = 
        "\nA farmer must get his fox, chicken, and grain safely\n"
        "across a river from the south bank to the north bank.\n"
        "The farmer can take at most one thing with him when\n"
        "he makes a trip across. Unfortunately, if the farmer\n"
        "leaves the fox and chicken together, the fox will eat\n"
        "the chicken. If the farmer leaves the chicken and the\n"
        "grain together, the chicken will eat the grain.\n\n"
        "Help the farmer by entering the name of what you want\n"
        "him to carry on his next trip to the opposite bank. If\n"
        "you want the farmer to cross the river without carrying\n"
        "anything, enter 'nothing' at the prompt.\n\n";
    char choice;
    Farmer farmer;
    River river;
    
    cout << endl << horizontalLine << endl;
    cout << "Welcome to the Fox, Chicken, Grain Riddle!";
    cout << endl << horizontalLine << endl;
    while (true)
    {
        cout << menu;
        cin >> choice;
        choice = tolower(choice);
        if (choice == 'q')
        {
            cout << "\nThanks for playing!\n";
            break;
        }
        else if (choice == 'i')
        {
            cout << instructions;
        }
        else if (choice == 'p')
        {
            while (true)
            {
                river.display();
                farmer.display();
                if (farmer.hasWonLost(&river))
                {
                    farmer.reset();
                    river.reset();
                    break;
                }
                farmer.crossRiver(&river);
            }
        }
        else
        {
            cout << "\nInvalid input!\n";
            cin.ignore(500, '\n');
        }
    }
    return 0;
}