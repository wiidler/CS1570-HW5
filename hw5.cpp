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
    const int SIZE = 6; // size of array
    int i = 0;
    srand(327); // set seed of 327
    newHomeowner player;
    cout << "Congratulations on finding your home sweet home!" << endl << endl;
    cout << "May I get your name please? ";
    cin >> player.m_homeownerName;
    cout << endl << "First, could you tell me the address of your new home? ";
    cin.ignore(); // clean out the input stream buffer
    getline(cin, player.m_address); 
    cout << endl << "Time for a fresh start, eh? What's the total number of acres of your property? ";
    player.m_garages = -1;
    cin >> player.m_acres;
    while (player.m_acres < 0){
        cout << endl << "Please enter a positive number!" << endl;
        cin >> player.m_acres;
    }
    cout << endl << "I'll wait for that housewarming party invite. How many garages does the house have? "; 
    cin >> player.m_garages;
    while (player.m_garages <0){
        cout << endl << "Please enter a positive number!" << endl;
        cin >> player.m_garages;
    }
    neighbor neighborhood[SIZE]; // initialize array
    initializeNeighbor(neighborhood, SIZE); // fill in array
    int goodNeighbors = 0;
    int badNeighbors = 0;
    int activeBadNeighbors = 0; // default values to set up home defender
    int changeAcres = 0;
    int changeGarages = 0;
    int initialAcres = player.m_acres;
    int initialGarages = player.m_garages;
    for(i = 0; i<SIZE; i++){ // determines the amount of good, bad, and bad active neighbors
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
    while((rounds <= 10) && (player.m_acres > 0) && (activeBadNeighbors != 0)){ // game that continues until 10 rounds pass, player's acres are 0 or less, or there are no more active bad neighbors
        cout << "ROUND " << rounds << endl;
        changeGarages = 0;
        changeAcres = 0;
        int tempValueGarages = player.m_garages;
        int tempValueAcres = player.m_acres;
        for(i=0; i<SIZE; i++){
            if(player.m_acres <= 0){
                player.m_acres = 0;
            }
            else if (neighborhood[i].m_active == true){
                if (neighborhood[i].m_good == true){
                    requestAssistance(player, neighborhood[i]);
                }
                else if (neighborhood[i].m_good == false){
                    defendHomeland(player, neighborhood[i]);
                }
                cout << endl;
            }
        }
        changeGarages = player.m_garages - tempValueGarages;
        changeAcres = player.m_acres - tempValueAcres;
        cout << "END-OF-ROUND SUMMARY:" << endl; // round summary
        if (changeAcres >= 0){
            cout << "     Current acres of land: " << player.m_acres << "   Change: +" << changeAcres << endl;
        }
        else{
            cout << "     Current acres of land: " << player.m_acres << "   Change: " << changeAcres << endl;
        }
        if (changeGarages >= 0){
            cout << "     Current number of garages: " << player.m_garages << "   Change: +" << changeGarages << endl;
        }
        else{
            cout << "     Current number of garages: " << player.m_garages << "   Change: " << changeGarages << endl;
        }
        rounds++;
        cout << endl;
    }
    cout << endl;
    cout << "HOME DEFENDER " << player.m_homeownerName << "! Let's run through your battle summary!" << endl; // End of game summary
    cout << "Home Defender:    " << player.m_homeownerName << endl;
    cout << "Home Address:     " << player.m_address << endl;
    cout << "Initial Acres of Land Owned:    " << initialAcres << endl;
    cout << "Final Acres of Land Owned:      " << player.m_acres << endl;
    cout << "Initial Number of Garages Owned:    " << initialGarages << endl;
    cout << "Final Number of Garages Owned:      " << player.m_garages << endl;
    cout << endl;
    for(i=0; i<SIZE; i++){ // Summary for all neighbors in the neighborhood
        cout << "Neighbor ID #: " << neighborhood[i].m_neighborId << endl;
        cout << "Acres of Land Owned:    " << neighborhood[i].m_acres << endl;
        cout << "Acres of Land Stolen:    " << neighborhood[i].m_stolenAcres << endl;
        cout << "Initial number of Garages Owned:    " << (neighborhood[i].m_garages - neighborhood[i].m_garagesBuilt) << endl;
        cout << "Final Number of Garages Owned:      " << neighborhood[i].m_garages << endl;
        cout << "Likeable?    ";
        if (neighborhood[i].m_good){
            cout << "GOOD!" << endl;
        }
        else{
            cout << "BAD!" << endl;
        }
        cout << "Status:      ";
        if (neighborhood[i].m_active){
            cout << "Active" << endl;
        }
        else{
            cout << "Inactive" << endl;
        }
        cout << endl;
    }
    cout << "Goodbye " << player.m_homeownerName << "! The next time you buy a house, make sure that there's no bad neighbors around it." << endl;
    return 0;
}