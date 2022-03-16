#ifndef NEIGHBOR_H
#define NEIGHBOR_H

#include "functions.h"
#include "newhomeowner.h"
#include "neighbor.h"
#include <iostream>

using namespace std;

/***********************STRUCT DEFINITIONS***********************/
struct neighbor{
    int m_neighborId;
    float m_acres;
    int m_garages;
    int m_garagesBuilt;
    float m_stolenAcres;
    bool m_good;
    bool m_active;
};

/***********************FUNCTION PROTOTYPES***********************/

#endif