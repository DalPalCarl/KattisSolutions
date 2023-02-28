/******************************************************************************
Author: Dallas Carlson
MCS-375 Algorithms
Date: 10/17/2022
*******************************************************************************/

#include <iostream>
#include <utility>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;


/*Let us use a different function to handle the core calculations.  Our goal
is to return a vector of indexes to iterate through. */

/*We already have our recurrence to implement:
              
              0                                             if i = 0 || w = 0
    m(i, w) = m(i-1, w)                                     if i > 0, w > 0, w[i] > w
              max{ v[i] + m(i-1, w - w[i]), m(i-1, w) }     if i > 0, w > 0, w[i] <= w
              
*/
vector<int> knap(int mw, int item, vector<int> val, vector<int> wei){
    /*We first build our table*/
    vector<vector<int>> table(item+1, vector<int>(mw+1));
    for(int i = 0; i <= item; i++){
        for(int j = 0; j <= mw; j++){
            
            /*Case 1 (artificial): If either the maximum weight or the number
            of items is 0*/
            if(i == 0 || j == 0){
                table[i][j] = 0;
            }
            
            /*Case 2: If the weight at i exceeds the maximum weight, we can
            eliminate it from the subsequence of items we are looking for*/
            else if(wei[i-1] > j){
                table[i][j] = table[i-1][j];
            }
            
            /*Case 3: This is where the magic happens; if the value can potentially
            be a part of the solution, we look at two values...
                1) adding the worth of the item currently being tested AND subtracting
                our maximum weight
                2) the value without using the current item being tested
            and which ever gives us a larger value is the optimal choice.*/
            else{
                table[i][j] = max(val[i-1] + table[i-1][j - wei[i-1]], table[i-1][j]);
            }
        }
    }
    
    int solution = table[item][mw];
    int solWeight = mw;
    
    /*Now we must build a maximizer table of indices*/
    
    vector<int> maximizer;
    for(int i = item; i > 0 && solution > 0; i--){
        if(solution == table[i-1][solWeight]){
            continue;
        }
        else{
            maximizer.push_back(i-1);
            solution = solution - val[i-1];
            solWeight = solWeight - wei[i-1];
        }
    }
    
    /*since we are looking for the indices for the items used, the maximizer vector
    will be our return value*/
    return maximizer;
    
}

int main()
{
    /*This while loop iterates through the input, separating each line (buffer) and storing
    them into a vector inputList*/
    
    int maxWeight, items, value, weight;
    while(cin >> maxWeight >> items){
        int v, w;
        vector<int> value;
        vector<int> weight;
        for(int i = 1; i <= items; i++){
            cin >> v >> w;
            value.push_back(v);
            weight.push_back(w);
        }
        
        vector<int> indices;
        indices = knap(maxWeight, items, value, weight);
        
        cout << indices.size() << endl;
        for(int x = indices.size()-1; x >= 0; x--){
            cout << indices[x] << " ";
        }
        cout << endl;
        
    }
    return 0;
    
}