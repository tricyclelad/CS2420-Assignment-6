//
//  Percolate.cpp
//  Assignment 6 Union Find
//
//  Created by Camron Blake Martinez on 11/23/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#include "Percolate.h"

Percolate::Percolate() : sets(NUM_OF_SETS)
{
    
    
}

int Percolate::openSite()
{
    int x = rand() % 20;
    int y = rand() % 20;
    //find a random spot on the grid that is blocked.
    while (grid.site[x][y].character == '-')
    {
         x = rand() % 20;
         y = rand() % 20;
    }
    //set that spot to open
    grid.site[x][y].character ='-';
    
    
//    a.	Given x and y     i = N*x+y
//    b.	Given i,  x = i/N  and   y = i%N
    
//    int convertedInt = 20 * x + y;
//    //Check spots orthogonally to the open spot and union them together
//    if (grid.site[x+1][y].character == '-')
//    {
//        int convertedInt1 = (20 * (x + 1)) + y;
//        cout << grid.site[x+1][y].ID << endl;
//        sets.unionSets(convertedInt1, convertedInt);
//    }
//    
//    if (grid.site[x-1][y].character == '-')
//    {
//        int convertedInt2 = (20 * (x-1)) + y;
//        cout << grid.site[x-1][y].ID << endl;
//        sets.unionSets(convertedInt2, convertedInt);
//    }
//    
//    if (grid.site[x][y+1].character == '-')
//    {
//        int convertedInt3 = 20 * x + (y+1);
//        cout << grid.site[x][y+1].ID << endl;
//        sets.unionSets(convertedInt3, convertedInt);
//    }
//    
//    if (grid.site[x][y-1].character == '-')
//    {
//        int convertedInt4 = 20 * x + (y-1);
//        cout << grid.site[x][y-1].ID << endl;
//        sets.unionSets(convertedInt4, convertedInt);
//    }
//    return convertedInt;
    //Check spots orthogonally to the open spot and union them together
    if (x+1<=19) {
        if (grid.site[x+1][y].character == '-')
        {
            sets.unionSets(grid.site[x+1][y].ID, grid.site[x][y].ID);
        
        }
    }
    if (x-1>=0) {
        if (grid.site[x-1][y].character == '-')
        {
            sets.unionSets(grid.site[x-1][y].ID, grid.site[x][y].ID);
        }
    }
    if (y+1<=19) {
        if (grid.site[x][y+1].character == '-')
        {
            sets.unionSets(grid.site[x][y+1].ID, grid.site[x][y].ID);
        }
    }
    if (y-1>=0) {
        if (grid.site[x][y-1].character == '-')
        {
            sets.unionSets(grid.site[x][y-1].ID, grid.site[x][y].ID);
        }
    }
        return grid.site[x][y].ID;
}

void Percolate::solve()
{
    int sitesOpened = 0;
    int siteID = -1;
    int siteRoot = -1;
    bool solved = false;
    
    while (!solved)
    {
        
        siteID = openSite();
        
        siteRoot = sets.findNoPath(siteID);
//                cout << "______________________" << endl;
//                grid.print();

        sitesOpened++;
        if (sets.v[siteRoot].lowestRow == 0 && sets.v[siteRoot].highestRow == 19 )
        {
            solved = true;
            cout << "______________________" << endl;
            grid.print();
//            sets.print();
//            grid.printID();
            cout << "Sites opened: " << sitesOpened << endl;
            float answer = float(sitesOpened)/400;
            cout << "Percolation threshold = " << sitesOpened << "/" << 400 << " = " << answer << endl;
            break;
        }
        else if (sitesOpened%50 == 0)
        {
            cout << "______________________" << endl;
            grid.print();
        }
//        cout << "______________________" << endl;
//        grid.print();
    }
    
    
    
}