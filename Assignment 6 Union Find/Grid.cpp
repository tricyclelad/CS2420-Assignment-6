//
//  Grid.cpp
//  Assignment 6 Union Find
//
//  Created by Camron Blake Martinez on 11/23/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#include "Grid.h"
#include <iostream>
using namespace std;

Grid::Grid()
{
    int IDcounter = 0;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            site[i][j].character='x';
            site[i][j].ID = IDcounter;
            site[i][j].row=i;
            site[i][j].column=j;
            IDcounter++;

        }
    }
}

void Grid::print()
{
    for (int i = 0; i < SIZE; i++){
        cout << "|";
        for (int j = 0; j < SIZE; j++)
            cout << site[i][j].character;
        cout << "|" << endl;
    }
    
}

void Grid::printID()
{
    for (int i = 0; i < SIZE; i++){
        cout << "|";
        for (int j = 0; j < SIZE; j++)
            cout << site[i][j].ID;
        cout << "|" << endl;
    }
    
}