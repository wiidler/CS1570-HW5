#include "functions.h"
#include "newhomeowner.h"
#include "neighbor.h"
#include <iostream>

using namespace std;

/***********************FUNCTION DEFINITIONS***********************/
void initializeNeighbor(neighbor array[], int SIZE){
    int i = 0;
    for(i = 0; i < SIZE; i++){
        int ID = i;
        float acres = ((rand()%(32))+19);
        int garages = (acres/10);
        int garagesBuilt = 0;
        float stolenAcres = 0;
        bool good = (((rand() % 10) + 1) <= 5)? true : false;
        bool active = true;
        neighbor neighbors = {ID, acres, garages, garagesBuilt, stolenAcres, good, active};
        array[i] = neighbors;
    }

    return;
}

void requestAssistance(newHomeowner & theNewHomeowner, neighbor & aGoodNeighbor){
    cout << "Good neighbor ID #" << aGoodNeighbor.m_neighborId << " has " << aGoodNeighbor.m_garages << " garages, and you have " << theNewHomeowner.m_garages << " garages." << endl;
    if (theNewHomeowner.m_garages < aGoodNeighbor.m_garages){
        int chance = (rand() % 10) + 1;
        if(chance <= 8){
            cout << "Excuse me... do you need an extra garage? The good neighbor got one for you!" << endl;
            theNewHomeowner.m_garages++;
            cout << "You have " << theNewHomeowner.m_garages << " garages now." << endl;
        }
        else{
            cout << "Garages? The good neighbor doesn't have any available." << endl;
        }
    }
    else if (theNewHomeowner.m_garages >= aGoodNeighbor.m_garages){
        int chance = (rand() % 10) + 1;
        if(chance <= 3){
            cout << "Excuse me... do you need an extra garage? The good neighbor got one for you!" << endl;
            theNewHomeowner.m_garages++;
            cout << "You have " << theNewHomeowner.m_garages << " garages now." << endl;
        }
        else{
            cout << "Garages? The good neighbor doesn't have any available." << endl;
        }
    }
    return;
}

void defendHomeland(newHomeowner & theNewHomeowner, neighbor & aBadNeighbor){
    cout << "Bad neighbor ID #" << aBadNeighbor.m_neighborId << " has " << aBadNeighbor.m_garages << " garages, and you have " << theNewHomeowner.m_garages << " garages." << endl;
    if(theNewHomeowner.m_garages < aBadNeighbor.m_garages){
        int chance = ((rand()%(100))+1);
        if(chance <= 53){
            float acresStolen = (aBadNeighbor.m_garages - theNewHomeowner.m_garages);
            cout << "The bad neighbor's garages look better than yours! So hand over " << acresStolen << " acres of land to your neighbor." << endl;
            theNewHomeowner.m_acres -= acresStolen;
            aBadNeighbor.m_acres += acresStolen;
            aBadNeighbor.m_stolenAcres += acresStolen;
            if (theNewHomeowner.m_acres < 0){
                theNewHomeowner.m_acres = 0;
            }
            cout << "You have " << theNewHomeowner.m_acres << " acres of land now." << endl;
            chance = ((rand()%(100))+1);
            if(chance <= 46){
                cout << "And guess what? The bad neighbor managed to build a new garage just now!" << endl;
                aBadNeighbor.m_garages++;
                aBadNeighbor.m_garagesBuilt++;
            }
        }
        else{
            cout << "The bad neighbor has no idea what's going on, so you are safe, run! " << endl;
        }
    }
    else if (theNewHomeowner.m_garages >= aBadNeighbor.m_garages){
        if(aBadNeighbor.m_stolenAcres != 0){
            int chance = ((rand()%(80))+1);
            if ((chance % 2) == 0){
                chance = ((rand()%(100))+1);
                if(chance <= 73){
                    cout << "You are in luck! You got back half of the stolen land from this bad neighbor." << endl;
                    float returnedAcres = (aBadNeighbor.m_stolenAcres / 2.0);
                    theNewHomeowner.m_acres += returnedAcres;
                    aBadNeighbor.m_stolenAcres -= returnedAcres;
                    if (returnedAcres == 1){
                        cout << returnedAcres << " acre of land reclaimed!" << endl;
                    }
                    else{
                        cout << returnedAcres << " acres of land reclaimed!" << endl;
                    }
                    if (aBadNeighbor.m_stolenAcres == 0){
                        cout << "Amazing work! This bad neighbor is now inactive." << endl;
                        aBadNeighbor.m_active = false;
                    }
                }
                else {
                    cout << "You are super lucky! You got back ALL of the stolen land from this bad neighbor." << endl;
                    float returnedAcres = aBadNeighbor.m_stolenAcres;
                    theNewHomeowner.m_acres += returnedAcres;
                    aBadNeighbor.m_stolenAcres = 0;
                    aBadNeighbor.m_active = 0;
                    if (returnedAcres == 1){
                        cout << returnedAcres << " acre of land reclaimed!" << endl;
                    }
                    else{
                        cout << returnedAcres << " acres of land reclaimed!" << endl;
                    }
                    if (aBadNeighbor.m_stolenAcres == 0){
                        cout << "Amazing work! This bad neighbor is now inactive." << endl;
                        aBadNeighbor.m_active = false;
                    }
                }
            }
            else{
                cout << "You are safe, run!" << endl;
            }
        }
        else if (aBadNeighbor.m_stolenAcres == 0){
            cout << "You are safe, run!" << endl;
        }
    }
    return;
}