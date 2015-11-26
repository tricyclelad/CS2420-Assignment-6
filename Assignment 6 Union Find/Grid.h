//
//  Grid.hpp
//  Assignment 6 Union Find
//
//  Created by Camron Blake Martinez on 11/23/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#ifndef Grid_h
#define Grid_h
#include <stdio.h>
const int SIZE = 20;
struct gridItems
{
    char character;
    int ID;
    int row;
    int column;
};
class Grid
{
//Using a 20-by-20 grid, (1) show the grid after every 50 sites have been opened and (2) show the
//grid when it finally percolates. Each site should be printed using the following notation:
//    a. a blank space for open
//        b. X for blocked
//            c. The edges of the grid are marked with ‘_‘  or ‘|’
public:
    Grid();
    void print();
    void printID();
    gridItems site[SIZE][SIZE];
    
};


#endif /* Grid_h */
