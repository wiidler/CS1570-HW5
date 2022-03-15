#include "functions.h"
#include "newhomeowner.h"
#include "neighbor.h"
#include <iostream>

using namespace std;

/***********************FUNCTION DEFINITIONS***********************/
void initializeNeighbor(neighbor array[], int SIZE){
    int i = 0;
    for(i = 0; i < SIZE; i++){
        int ID = i+1;
        int acres = ((rand()%(32))+19);
        int garages = (acres/10) % 10;
        bool good = (rand()%(2));
        bool active = false;
        if(good){
            bool active = true;
        }
        neighbor firstPerson = {ID, acres, garages, good, active};
        array[i] = firstPerson;
    }

    return;
}

void requestAssistance(newHomeowner theNewHomeowner, neighbor aGoodNeighbor){
    return;
}

void defendHomeland(newHomeowner theNewHomeowner, neighbor aBadNeighbor){
    return;
}