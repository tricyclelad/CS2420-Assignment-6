//
//  DisjointSet.cpp
//  Assignment 6 Union Find
//
//  Created by Camron Blake Martinez on 11/23/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#include "DisjointSet.h"
#include <iostream>
using namespace std;

//Set the initial values in the set to -1
//Constructor

DisjointSet::DisjointSet(int elements) : v(elements)
{
    for (int i = 0; i < v.size(); i++) {
        v[i].first = i;
        v[i].second = 1;
        
    }
    
}

//Looks to see if the item is the root.
//Does this by comparing the parent ID and the element number of the array,
//if they are the same then it is a root.
//if it isn't, recursively finds on the value of the parent ID
//and uses path compression to assign new parent id
int DisjointSet::find(int x) 
{
    if (v[x].first==x)
        return x;
    else
    {
        
        return v[x].first = find(v[x].first);
    }
}
//Find with no path compression
int DisjointSet::findNoPath(int x)
{
    if (v[x].first==x)
        return x;
    else
       // v[x].second = 0;
        return findNoPath(v[x].first);
}
//smart union, union by size
void DisjointSet::unionSets(int root1, int root2)
{
    int realRoot1 = findNoPath(root1);//Checks if they are already unioned.
    int realRoot2 = findNoPath(root2);
    if (realRoot1 == realRoot2)
    {
        cout << root1 << " and " << root2<< " are already in a unioned set" << endl;
        return;
    }
    
    if (v[realRoot2].second > v[realRoot1].second)
        v[realRoot1].first = realRoot2;
    else
    {
        if(v[realRoot1].second == v[realRoot2].second)
        v[realRoot1].second++;
        v[realRoot2].first = realRoot1;
    }
}
//Prints out the contents of the vector
void DisjointSet::print()
{
    cout << "i |ID|HEIGHT " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << i << " |" << v[i].first << " |" << v[i].second << endl;
        
    }

}


