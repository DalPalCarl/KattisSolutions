#include <string>
#include <iostream>

using namespace std;

int main(){
    int test;
    string s1, s2, s3;
    cin >> test;
    for(int i = 0; i < test; i++){
        s3 = "";
        cin >> s1 >> s2;
        for(int j = 0; j < s1.size(); j++){
            if(s1[j] == s2[j]){s3.append(".");}
            else{s3.append("*");}
        }
        cout << s1 << endl << s2 << endl << s3 << endl;
    }
    return 0;
}