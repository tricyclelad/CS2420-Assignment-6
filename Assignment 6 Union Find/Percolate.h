//
//  Percolate.hpp
//  Assignment 6 Union Find
//
//  Created by Camron Blake Martinez on 11/23/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#ifndef Percolate_h
#define Percolate_h

#include <stdio.h>
#include "Grid.h"
#include "DisjointSet.h"

const int NUM_OF_SETS = 400;

class Percolate
{
public:
    Percolate();
    Grid sites;
    DisjointSet sets;
    
private:
    
};
#endif /* Percolate_h */
