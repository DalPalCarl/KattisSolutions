/******************************************************************************
Author: Dallas Carlson
MCS-375 Algorithms
Date: 11/5/2022
*******************************************************************************/

#include <iostream>
#include <utility>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int n, x, y;

int avoidLand2(vector<int> v, int s){
    
    /*We create two additional vectors to separate our problem:
    if there are two pawns in the same row/column, then there exists
    a row/column that is empty.  We must define which indices are holding
    doubles and which aren't holding anything.*/
    vector<int> emptySpace, doubledSpace;
    int moves = 0;

    for(int i = 1; i <= s; i++){
        if(v[i] == 0){
            emptySpace.push_back(i);
        }
        else{
           for(int j = v[i]; j >= 2; j--){
            doubledSpace.push_back(i);
            } 
        }
    }

    /*We aren't concerned with the order in which we move these pawns,
    just the fact that we move them.  So we compare both lists and calculate
    the difference between a doubled spot and an empty spot (i.e. how many moves
    we have to move it to get there)*/

    for(int i = 0; i < doubledSpace.size(); i++){
        moves += abs(doubledSpace[i] - emptySpace[i]);
    }
    
    return moves;
}



int main()
{
    int row, col;
    
    /*We first load input into two separate vectors: one for the rows, one for the columns
    Our goal is to modify the arrays such that no two elements repeat in the same array;
    this will give us a board in which no two pawns are in the same row or column*/

    cin >> n;
    vector<int> I(n+1, 0);
    vector<int> J(n+1, 0);
    
    /*This for loop will give us the number of occurrances of a pawn in a given row
    or column (including 0 if no such pawn exists).  This is how we determine what 
    needs to get moved and where*/

    for(int i = 0; i < n; i++){
        cin >> y;
        cin >> x;
        I[y]++;
        J[x]++;
    }
    
    /*We can run the same function to calculate both row and column coordinates*/
    row = avoidLand2(I, n);
    col = avoidLand2(J, n);
    

    /*At last, we need to calculate the number of moves in both rows and columns,
    simply by getting their sum.*/
    cout << row + col << endl;
    
    return 0;
}
