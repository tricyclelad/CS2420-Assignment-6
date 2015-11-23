//
//  DisjointSet.cpp
//  Assignment 6 Union Find
//
//  Created by Camron Blake Martinez on 11/23/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#include "DisjointSet.h"

//Set the initial values in the set to -1
//Constructor

DisjointSet::DisjointSet(int elements)
{
    for (int i = 0; i < SIZE; i++) {
        v[i].first = i;
        v[i].second = 1;
        
    }
    
}

