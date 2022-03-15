#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "functions.h"
#include "newhomeowner.h"
#include "neighbor.h"
#include <iostream>
#include <cmath>
using namespace std;

/***********************FUNCTION PROTOTYPES***********************/
// Definition:
// Pre:
// Post:
void initializeNeighbor(neighbor array[], int SIZE);
// Definition:
// Pre:
// Post:
void requestAssistance(newHomeowner & theNewHomeowner, neighbor & aGoodNeighbor);
// Definition:
// Pre:
// Post:
void defendHomeland(newHomeowner & theNewHomeowner, neighbor & aBadNeighbor);

#endif