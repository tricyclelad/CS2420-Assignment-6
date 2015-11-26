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
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int NUM_OF_SETS = 400;

class Percolate
{
public:
    Percolate();
    Grid grid;
    DisjointSet sets;
    int openSite();
    void solve();
private:
    
};
#endif /* Percolate_h */
