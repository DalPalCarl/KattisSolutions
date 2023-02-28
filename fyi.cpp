#include <iostream>
using namespace std;
int main(){
    int number;
    cin >> number;
    number = (int)number / 10000;
    
    if(number == 555){
        cout << 1;
    }
    else{cout << 0;}
    
    cout << endl;
    return 0;
}