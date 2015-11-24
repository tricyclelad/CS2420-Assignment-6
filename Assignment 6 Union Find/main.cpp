//
//  main.cpp
//  Assignment 6 Union Find
//
//  Created by Camron Blake Martinez on 11/23/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#include <iostream>
#include "DisjointSet.h"
using namespace std;
void test();
void doAFind(DisjointSet set);
int main() {
    
    test();
    
    return 0;
}

void test()
{
    //test code for my disjoinset class
    DisjointSet set(10);
    set.print();
    doAFind(set);
    cout << "union:0,1|2,3|4,5|6,7|8,9" << endl;
    set.unionSets(0, 1);
    set.unionSets(2, 3);
    set.unionSets(4, 5);
    set.unionSets(6, 7);
    set.unionSets(8, 9);
    cout << "print out the vector again" <<endl;
    set.print();
    doAFind(set);
    cout << "call a union on a set with values that aren't the roots and see if it correctly groups them" << endl;
    cout << "union:1,3|5,7|" << endl;
    set.unionSets(1, 3);
    set.unionSets(5, 7);
    set.print();
    cout << "then union two larger sets" << endl;
    cout << "union:9,7" << endl;
    set.unionSets(9, 7);
    set.print();
    cout << "try to union two things that are already grouped" << endl;
    cout << "union:0,1" << endl;
    set.unionSets(0, 1);
    set.print();
    cout << "union the two big trees" << endl;
    cout << "union:9,3" << endl;
    set.unionSets(9, 3);
    set.print();
    cout << "Demonstrate path compression with a find on 1,3,7,9" << endl;
    set.find(1);
    set.print();
    set.find(3);
    set.print();
    set.find(7);
    set.print();
    set.find(9);
    set.print();
    cout << "As we can see, the height DOES NOT get updated after finds." << endl;
}
void doAFind(DisjointSet set)
{
    cout << "Do a find on each number" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Find on "<< i << " = " << set.find(i) << endl;
    }
}
