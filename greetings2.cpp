#include <iostream>
#include <string>

using namespace std;

int main(){
    string greet, e;
    cin >> greet;
    
    e = "";
    int count = 0;
    
    for(int i = 0; i < greet.size(); i++){
        if(greet[i] == 'e'){count++;}
    }
    
    for(int j = 0; j < count; j++){
        e.append("ee");
    }
    cout << 'h' << e << 'y' << endl;
    
    return 0;
}