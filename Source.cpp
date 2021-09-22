#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <conio.h>
#include<windows.h>

using namespace std;

const string qualities[6] = { "Unowned", "Common", "Uncommon", "Rare", "Legendary", "Epic" };


//This should print out the level of every character
void printLevels(int levels[], string letters[]){
    for (int i = 0; i < 26; i++) {
        cout << "The " << letters[i] << " is level " << levels[i] << endl;
    }
    return;
}

//This should level up one random character
void lootbox(int levels[], string letters[], int &money, int &cost) {
    
    if (money >= cost){
        int loot = rand() % 26;
        int qualityRoll = rand() % 100;
        int qualityLevel = 0;
        //Common, Uncommon, Rare, Legendary, Epic
        //50, 30, 15, 4, 1 
        if (qualityRoll < 50) {
            qualityLevel = 1;
        }
        else if (qualityRoll < 80) {
            qualityLevel = 2;
        }
        else if (qualityRoll < 95) {
            qualityLevel = 3;
        }
        else if (qualityRoll < 99) {
            qualityLevel = 4;
        }
        else {
            qualityLevel = 5;
        }

        if (levels[loot] < qualityLevel) {
            cout << "Congratulations! You now own a " << qualities[qualityLevel] << " (";
            for (int i = 0; i < qualityLevel; i++) {
                cout << "*";
            }
            cout << ") " << letters[loot] << "!" << endl;
            levels[loot] = qualityLevel;
        }
        else {
            cout << "Sorry, you alreay own a higher quality" << letters[loot] << "! Nothing happened." << endl;
        }



        //cout << "The '" << letters[loot] << "' went from " << levels[loot] << " to " << levels[loot] + 1 << "!" << endl;
        //levels[loot] = levels[loot] + 1;
        money -= cost;
        //cout << "Thanks for the Alphaether! 5% of all Alphaether spent goes towards supporting letters in need." << endl;

        cout << endl;
        //cost++;
        return;
    }
    else {
        cout << "Sorry, you need to spend " << cost << " Alphaether to open a lootbox! Consider enabling in-app purchases." << endl;
        return;
    }
}

int owned(int levels[]) {
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (levels[i] > 0) {
            count++;
        }
    }
    return count;
}

int powerLevel(int levels[]) {
    int count = 0;
    for (int i = 0; i < 26; i++) {
        count += levels[i];
    }
    return count;
}

void countdown() {
    for (int i = 1; i < 11; i++) {
        cout << "(" << i << "/10) completed" << endl;
        Sleep(100);
    }
    return;
}

//
int main()
{
    cout << "Welcome to..." << endl;
    cout << "THE FINAL ALPHABET WAR" << endl;
    system("pause");
    srand(time(NULL));
    int levels[26] = {};
    string letters[26] = { "Archerstopper" , "Barbarianking" , "Crabmaster", "Demonslayer" , "Elephantrider" , "Firestarter" , "Ghostwalker" , "Hoodwink", "Intransient" , "Jokemaker" , "Killmaker", "Legendkeeper", "Merchant", "Needlesmith", "Orangebender", "Pickpocket", "Quailmonger", "Repairman", "Swordslinger", "Toothgrower", "Understomach", "Vowbreaker", "Wonderbreaker", "Xeviant", "Yelltaker", "Zapmayor"};
    string userInput;
    char userI;
    int sentinelValue = 0;
    int money = 0;
    int cost = 1;
    while (sentinelValue != 1) {

        system("CLS");
        cout << "You own " << owned(levels) << " Alphabet Warriors" << endl;
        cout << "Total Alphabet Power Level: " << powerLevel(levels) << endl;
        cout << "Alphaether owned: " << money << endl;
        cout << "What do you want to do?" << endl;
        cout << "Type 0 to quit" << endl;
        cout << "Type 1 to check your Alphabet Army" << endl;
        cout << "Type 2 to summon an Alphabet Warrior (-" << cost << " Alphaether)" << endl;
        cout << "Type 3 to earn Alphaether" << endl;
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
                lootbox(levels, letters, money, cost);
                system("pause");
                break;
            case '3':
                money++;
                cout << "Harvesting Alphaether..." << endl;
                countdown();
                cout << "You earned 1 Alphaether!" << endl;
                system("pause");
                break;
                 
        }
    }
}
