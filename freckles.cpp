/******************************************************************************
Author: Dallas Carlson
MCS-375 Algorithms
Date: 12/9/2022
*******************************************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;


struct edge {
    int v1;
    int v2;
    long double dist;
};

long double distance(pair<long double, long double> p1, pair<long double, long double> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int find(vector<int>& disjoint, int a) {
    if(disjoint[a] == -1) {
        return a;
    }

    return find(disjoint, disjoint[a]);
}

void join(vector<int>& disjoint, int a, int b) {
    a = find(disjoint, a);
    b = find(disjoint, b);

    if(a == b) {
        return;
    }

    disjoint[a] = b;
}

bool lessThan(edge left, edge right){
	return left.dist < right.dist;
}

int main() {
    int cases;
    cin >> cases;

    bool first = true;
    while(cases--) {
        if(first) {first = false;}
        
        else {cout << endl;}

        int n;
        cin >> n;
        vector<pair<long double, long double>> input;
        for(int i = 0; i < n; i++){
            pair<long double, long double> line;
            cin >> line.first >> line.second;
            input.push_back(line);
        }

        vector<edge> edges;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                edge e = {i, j, distance(input[i], input[j])};
                edges.push_back(e);
            }
        }

        sort(edges.begin(), edges.end(), lessThan);

        long double total = 0;
        vector<int> disjoint(n, -1);

        for(auto& i : edges) {
            if(find(disjoint, i.v1) != find(disjoint, i.v2)) {
                total += i.dist;
                join(disjoint, i.v1, i.v2);
            }
        }

        cout << fixed;
        cout.precision(2);
        cout << total << endl;
    }
    return 0;
}