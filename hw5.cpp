// Programmer: Will Weidler
// ID: wawq97
// Date: 3/11/22
// File: hw5.cpp
// Assignment: HW5
// Purpose: This file contains a program that helps a new homeowner defend their home from bullies.

#include "functions.h"
#include "newhomeowner.h"
#include "neighbor.h"
#include <iostream>
using namespace std;

int main(){
    const int SIZE = 6;
    int i = 0;
    srand(11);
    newHomeowner player;
    cout << "Congratulations on finding your home sweet home!" << endl << endl;
    cout << "May I get your name please? ";
    cin >> player.m_homeownerName;
    cout << endl << "First, could you tell me the address of your new home? ";
    cin.ignore(); // clean out the input stream buffer
    getline(cin, player.m_address); 
    cout << endl << "Time for a fresh start, eh? What's the total number of acres of your property? ";
    cin >> player.m_acres;
    cout << endl << "I'll wait for that housewarming party invite. How many garages does the house have? "; 
    cin >> player.m_garages;
    neighbor neighborhood[SIZE];
    initializeNeighbor(neighborhood, SIZE);
    int goodNeighbors = 0;
    int badNeighbors = 0;
    int activeBadNeighbors = 0;
    int changeAcres = 0;
    int changeGarages = 0;
    for(i = 0; i<SIZE; i++){
        if (neighborhood[i].m_good){
            goodNeighbors++;
        }
        else if (!neighborhood[i].m_good){
            badNeighbors++;
            if (neighborhood[i].m_active){
                activeBadNeighbors++;
            }
        }
    }
    cout << endl << "Sweet cookies! The neighborhood is lucky to have you, " << player.m_homeownerName << "! Looks like you have " << goodNeighbors << " good neighbors and " << badNeighbors << " bad neighbors, and they can't wait to show you around." << endl << endl;
    int rounds = 1;
    while((rounds <= 10) && (player.m_acres > 0) && (activeBadNeighbors != 0)){
        for(i=0; i<SIZE; i++){
            if (neighborhood[i].m_active == true){
                if (neighborhood[i].m_good == true){
                    changeGarages = player.m_garages;
                    requestAssistance(player, neighborhood[i]);
                    changeGarages = player.m_garages - changeGarages;
                }
                else if (neighborhood[i].m_good == false){
                    defendHomeland(player, neighborhood[i]);
                }
            }
        }
        cout << "END-OF-ROUND SUMMARY:" << endl;
        cout << "     Current acres of land: " << player.m_acres << "   Change: " << changeAcres << endl;
        cout << "     Current number of garages: " << player.m_garages << "   Change: " << changeGarages << endl;
        rounds++;
    }
    return 0;
}