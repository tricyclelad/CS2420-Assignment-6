//
//  DisjointSet.hpp
//  Assignment 6 Union Find
//
//  Created by Camron Blake Martinez on 11/23/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#ifndef DisjointSet_h
#define DisjointSet_h

#include <stdio.h>
#include <vector>
using namespace std;
const int SIZE = 30;
class DisjointSet
{
public:
    explicit DisjointSet(int elements);
    
    int find(int x) const;
    int find(int x);
    
    void unionSets(int root1, int root2);
    
private:
    pair<int, int> v[30];
    
};

#endif /* DisjointSet_h */
