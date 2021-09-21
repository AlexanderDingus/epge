#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <conio.h>
using namespace std;

//This should print out the level of every character
void printLevels(int levels[], string letters[]){
    for (int i = 0; i < 26; i++) {
        cout << "The " << letters[i] << " is level " << levels[i] << endl;
    }
    return;
}

//This should level up one random character
void lootbox(int levels[], string letters[]) {
    int loot = rand() % 26;
    cout << "The '" << letters[loot] << "' went from " << levels[loot] << " to " << levels[loot] + 1 << "!" << endl;
    levels[loot] = levels[loot] + 1;
    return;
}

int total(int levels[]) {
    int owned = 0;
    for (int i = 0; i < 26; i++) {
        if (levels[i] > 0) {
            owned++;
        }
    }
    return owned;
}

//
int main()
{
    cout << "Welcome to..." << endl;
    cout << "THE FINAL ALPHABET WAR" << endl;
    srand(time(NULL));

    int levels[26] = {};
    string letters[26] = { "Archerstopper" , "Barbarianking" , "Crabmaster", "Demonslayer" , "Elephantrider" , "Firestarter" , "Ghostwalker" , "Hoodwink", "Intransient" , "Jokemaker" , "Killmaker", "Legendkeeper", "Merchant", "Needlesmith", "Orangebender", "Pickpocket", "Quailmonger", "Repairman", "Swordslinger", "Toothgrower", "Understomach", "Vowbreaker", "Wonderbreaker", "Xeviant", "Yelltaker", "Zapmayor"};
    string userInput;
    char userI;
    int sentinelValue = 0;
    while (sentinelValue != 1) {

        system("CLS");
        cout << endl;
        cout << "You own " << total(levels) << " Alphabet Warriors" << endl;
        cout << "What do you want to do?" << endl;
        cout << "Type 0 to quit" << endl;
        cout << "Type 1 to check your Alphabet Army's levels" << endl;
        cout << "Type 2 to open a lootbox" << endl;
        //cin >> userInput;
        //userI = userInput[0];
        userI = _getch();
        cout << endl;
        switch(userI){
            case '0':
                cout << "Quitting !" << endl;
                system("pause");
                sentinelValue = 1;
                break;
            case '1':
                printLevels(levels, letters);
                system("pause");
                break;
            case '2':
                lootbox(levels, letters);
                system("pause");
                break;
        }
    }
}
