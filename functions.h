#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "functions.h"
#include "newhomeowner.h"
#include "neighbor.h"
#include <iostream>

using namespace std;

/***********************FUNCTION PROTOTYPES***********************/
// Definition: Creates a neighborhood in an array with size SIZE.
// Pre: An intialized array with type neighbor and a variable defined as SIZE
// Post: Creates an array of a neighborhood with ID, acres, garages, goodness value, and status
void initializeNeighbor(neighbor array[], int SIZE);
// Definition: If the new homeowner encounters a good neighbor, the neighbor has a chance to donate garages
// Pre: The new homeowner defined in the struct newHomeowner and a good neighbor that was initialized in the initializeNeighbor function
// Post: Updates both struct info based on randomly generated numbers
void requestAssistance(newHomeowner & theNewHomeowner, neighbor & aGoodNeighbor);
// Definition: If the new homeowner encounters a bad neighbor, the neighbor may try to steal land
// Pre: The new homeowner defined in the struct newHomeowner and a bad neighbor that was initialized in the initializeNeighbor function
// Post: Updates both struct info based on randomly generated numbers
void defendHomeland(newHomeowner & theNewHomeowner, neighbor & aBadNeighbor, int activeBadNeighbors);

#endif