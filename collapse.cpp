/******************************************************************************
Author: Dallas Carlson
MCS-375 Algorithms
Date: 11/17/2022
*******************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

/*Input:

4 --- 0 <= N <= 100 000 --- number of islands in Insumulia

N lines {

    0 0 --- two ints: T[i] and K[i]
        T[i] --- 0 <= T[i] <= 50 000 --- amt of goods the i'th island
                                        needs to receive to survive.

        K[i] --- 0 <= K[i] <= N-1 --- # of other islands that the i'th
                                    islands receives goods from.

    25 3 1 10 3 10 4 10
    10 1 2 10
    10 1 2 10
}
*/


struct To_Value {
    int to;
    int value;
};

int main(){
    
    int n, k, j, t, v;
    vector<int> extra;
    vector<To_Value> pointsTo[100000];
    queue<int> deadIslands;

    cin >> n;
    
    for (int i = 0; i < n; i++){
        extra.push_back(0);
    }
    
    for (int i = 0; i < n; i++){
        cin >> t >> j;
        while (j > 0){
            cin >> k >> v;
            To_Value entry;
            entry.to = i;
            entry.value = v;
            pointsTo[k-1].push_back(entry);
            extra[i] = extra[i] + v;
            j--;
        }
        extra[i] = extra[i] - t;

    }

    deadIslands.push(0);
    int count = 0;
    extra[0] = -1;

    while(!deadIslands.empty()){
        int dead = deadIslands.front();
        deadIslands.pop();
        for (auto island = pointsTo[dead].begin(); island != pointsTo[dead].end(); island++){
            if (extra[island->to] >= 0){
                extra[island->to] = extra[island->to] - island->value;
                if (extra[island->to] < 0){
                    deadIslands.push(island->to);
                }
            }
        }
        count++;
    }

    cout << n - count << endl;
    

    return 0;
}