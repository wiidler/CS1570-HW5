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
        int acres = ((rand()%(32))+19);
        int garages = (acres/10) % 10;
        bool good = (rand()%(2));
        bool active = true;
        /* if(good){
            bool active = true;
        }
        else if (!good){
            bool active = false;
        } */
        neighbor neighbors = {ID, acres, garages, good, active};
        array[i] = neighbors;
    }

    return;
}

void requestAssistance(newHomeowner theNewHomeowner, neighbor aGoodNeighbor){
    cout << "Good neighbor ID #" << aGoodNeighbor.m_neighborId << " has " << aGoodNeighbor.m_garages << " garages, and you have " << theNewHomeowner.m_garages << " garages." << endl;
    if (theNewHomeowner.m_garages < aGoodNeighbor.m_garages){
        int chance = (rand() % 10) + 1;
        if(chance <= 8){
            theNewHomeowner.m_garages++;
            aGoodNeighbor.m_garages--;
        }
    }
    else if (theNewHomeowner.m_garages >= aGoodNeighbor.m_garages){
        int chance = (rand() % 10) + 1;
        if(chance <= 3){
            theNewHomeowner.m_garages++;
            aGoodNeighbor.m_garages--;
        }
    }
    return;
}

void defendHomeland(newHomeowner theNewHomeowner, neighbor aBadNeighbor){

    return;
}