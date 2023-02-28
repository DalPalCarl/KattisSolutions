
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Entry{
    int tE;
    char problem;
    string correctness;
};

int main(){
    
    vector<Entry> sL;
    int a;
    char b;
    string c;
    
    while(cin >> a >> b >> c){
        Entry input;
        input.tE = a;
        input.problem = b;
        input.correctness = c;
        sL.push_back(input);
    }
    
    int solved = 0;
    int finalScore = 0;
    unordered_map<char, int> penalty = {};
    
    for(int i = 0; i < sL.size(); i++){
        if(sL[i].correctness == "right"){
            finalScore += sL[i].tE + (penalty[sL[i].problem] * 20);
            solved++;
        }
        else{
            penalty[sL[i].problem] += 1;
        }
    }
    
    cout << solved << " " << finalScore << endl;
    return 0;
}
