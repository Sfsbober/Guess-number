// main.cpp : You have to guess number which computer guessed.
//

////////////////////////////
#include <iostream>
#include <random>
#include <stdlib.h>
#include <conio.h>
//
using namespace std;

int Check(int compn, int playerg); // Checks for matches 
void GetNum(int* h, int* d, int* u, int num); // Finds Hundreds, dozens and units of number

int main()
{
    // random from 100 to 999
    // Using Mersenne Vortex
    ///////////////////////////////////////////////////////
    random_device random;
    mt19937 mers(random());
    uniform_int_distribution<int> dist(100, 999);
    ///////////////////////////////////////////////////////

    int compn; // computer's number
    int playerguess; // player's guess
    int countNums = 0; // How many number player guessed right?

    compn = dist(mers); // Now variable "compn" has random number

    // Just a description
    cout << "Let's play a game.\nYou need to guess number, which I choosed. \nGuess from 100 to 999...\n\nPress any key to continue...";
    _getch();
    system("cls");

    while (true) // main loop
    {
        cout << "Enter your guess: ";
        cin >> playerguess;

        if (playerguess < 100 || playerguess > 999) // Check for idiots, who entered num < 100 or > 999 :)
        {
            cout << "\t\tIncorrect input!! Please try again...\n";
            continue;
        }
            
        // Function "Check()" returns countn (How many number player guessed right?)
        countNums = Check(compn, playerguess);

        // if countNums == 0 or 1 or 2 or 3, then do, what you see in this if - else if
        if (countNums == 0)
            cout << "Incorrect. 0 / 3 numbers are on its place.\n\n";
        else if (countNums == 1)
            cout << "Incorrect. 1 / 3 number is on its place.\n\n";
        else if (countNums == 2)
            cout << "Incorrect. 2 / 3 numbers are on its place.\n\n";
        else if (countNums == 3)
        {
            cout << "It's correct! You won!\n";
            break;
        }
    }

    // It needs in order to console doesn't close (_getch();)
    _getch();
    return 0;
}

int Check(int compn, int playerg)
{
    int chundred, cdozens, cunits, phundred, pdozens, punits; // 'c-' - comp, 'p-' - player
    int countn = 0;
    GetNum(&chundred, &cdozens, &cunits, compn);
    GetNum(&phundred, &pdozens, &punits, playerg);

    if (phundred == chundred)
        countn++;
    if (pdozens == cdozens)
        countn++;
    if (punits == cunits)
        countn++;

    return countn;
}

void GetNum(int* h, int* d, int* u, int num)
{
    // my method to find hundreds, dozens and units
    // h - hundreds, d - dozens, u - units, num - comp num or player num
    *h = num / 100;
    *d = *h * 100;
    *d = num - *d;
    *d = *d / 10;
    *u = num / 10;
    *u = num % *u;
}