/******************************************************************************
Author: Dallas Carlson
MCS-375 Algorithms
Date: 10/17/2022
*******************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int main(){

	/*
	We first get our map and two dynamic arrays set up with our given inputs
	*/
	
    long long n, m;
    cin >> n;
    cin >> m;
    
    vector<long> vec1, vec2;
    
    unordered_map<long,long> differences;

	

	for (long i = 0; i < n; i++){
		long temp;
		cin >> temp;
		vec1.push_back(temp);
	}

	for (long i = 0; i < m; i++){
		long temp;
		cin >> temp;
		vec2.push_back(temp);
	}


	/*
		Now we must calculate each combination of m - n, since we don't know how they align
	*/

	for(int i : vec1){
		for(int j : vec2){
			differences[j-i]++;
		}
	}

    long topValue = 0;
    long topOccurrences = 0;
    
    /*Now, we must filter out all negative and zero times and count the rest
    There are three possibilities:
        1) if differences[i] > differences[i-1]
        2) if differences[i] == differences[i-1]
        3) if differences[i] < differences[i-1]
    */
    
	for(auto i : differences){
	    if (i.first > 0 && i.second > topOccurrences){
	        topValue = i.first;
	        topOccurrences = i.second;
	    }
	    
	    /*The first if statement covers cases 1 and 3, but now we must account for case 2 
	      Since both numbers will have the same number of occurrences, it will remain the topOccurrences*/
	    if (i.first > 0 && i.second == topOccurrences){
	        topValue = min(i.first, topValue);
	    }
	    
	}
    
    cout << topValue;
    return 0;
}