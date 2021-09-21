#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

void printLevels(int levels[], string letters[]){
    for (int i = 0; i < 26; i++) {
        cout << "The " << letters[i] << " is level " << levels[i] << endl;
    }
    return;
}

void lootbox(int levels[], string letters[]) {
    int loot = rand() % 26;
    cout << "The '" << letters[loot] << "' went from " << levels[loot] << " to " << levels[loot] + 1 << "!" << endl;
    levels[loot] = levels[loot] + 1;
    return;
}

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
        cout << endl;
        cout << "What do you want to do?" << endl;
        cout << "Type 0 to quit" << endl;
        cout << "Type 1 to check your Alphabet Army's levels" << endl;
        cout << "Type 2 to open a lootbox" << endl;
        cin >> userInput;
        userI = userInput[0];
        switch(userI){
            case '0':
                cout << "Quitting !" << endl;
                sentinelValue = 1;
                break;
            case '1':
                printLevels(levels, letters);
                break;
            case '2':
                lootbox(levels, letters);
                break;
        }
    }
}