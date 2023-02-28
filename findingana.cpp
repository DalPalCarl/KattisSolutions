#include <iostream>
#include <string>

using namespace std;

int main(){
    bool flag = false;
    string s;
    
    cin >> s;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a'){flag = true;}
        if(flag){cout << s[i];}
    }
    cout << endl;
    return 0;
}