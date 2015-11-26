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
        v[i].parentID = i;
        v[i].height = 1;
        
    }
    
    int elementCount = 0;
    for (int j = 0 ; j < 20; j++) {
        for (int k = 0 ; k < 20; k++) {
            v[elementCount].lowestRow = j;
            v[elementCount].highestRow = j;
            elementCount++;
        }
    }
    
    
//    for (int j = 0 ; j < 20; j++) {
//        for (int k = 0 ; k < 20; k++) {
//            v[elementCount].lowestRow = j;
//            v[elementCount].highestRow = j;
//            elementCount++;
//        }
//    }
    
}

//Looks to see if the item is the root.
//Does this by comparing the parent ID and the element number of the array,
//if they are the same then it is a root.
//if it isn't, recursively finds on the value of the parent ID
//and uses path compression to assign new parent id

int DisjointSet::find(int x) 
{
    if (v[x].parentID==x)
        return x;
    else
    {
        
        return v[x].parentID = find(v[x].parentID);
    }
}
//Find with no path compression
int DisjointSet::findNoPath(int x)
{
    if (v[x].parentID==x)
        return x;
    else
        return findNoPath(v[x].parentID);
}
//smart union, union by size
void DisjointSet::unionSets(int root1, int root2)
{
    int realRoot1 = find(root1);//Checks if they are already unioned.
    int realRoot2 = find(root2);
    
//    int realRoot1 = findNoPath(root1);//Checks if they are already unioned.
//    int realRoot2 = findNoPath(root2);
//    
    if (realRoot1 == realRoot2)
    {
        //cout << root1 << " and " << root2<< " are already in a unioned set" << endl;
        return;
    }
    //Check the heights to see which is bigger, assign the smaller to the larger
    if (v[realRoot2].height > v[realRoot1].height)
    {
        v[realRoot1].parentID = realRoot2;
        //Compare the highest rows and assign the root the higher row.
        if (v[realRoot2].highestRow < v[realRoot1].highestRow){
            v[realRoot2].highestRow = v[realRoot1].highestRow;
        }
        
        if (v[realRoot2].lowestRow > v[realRoot1].lowestRow){
            v[realRoot2].lowestRow = v[realRoot1].lowestRow;
        }
        return;
    }
    else
    {
        if(v[realRoot1].height == v[realRoot2].height)
            v[realRoot1].height++;
        
        v[realRoot2].parentID = realRoot1;
        
        //Compare the highest rows and assign the root the higher row.
        if (v[realRoot1].highestRow < v[realRoot2].highestRow){
            v[realRoot1].highestRow = v[realRoot2].highestRow;
        }
        
        if (v[realRoot1].lowestRow > v[realRoot2].lowestRow){
            v[realRoot1].lowestRow = v[realRoot2].lowestRow;
        }
        return;
        
    }
}
//Prints out the contents of the vector
void DisjointSet::print()
{
    cout << "i |ID|HEIGHT|LOW ROW|HIGH ROW " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << i << " |" << v[i].parentID << " |" << v[i].height << "     |" <<  v[i].lowestRow <<"     |" << v[i].highestRow <<endl;
        
    }

}


