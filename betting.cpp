#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    double a, b;
    cin >> n;
    
    a = 100.0 / n;
    b = 100.0 / (100.0 - n);
    
    cout << setprecision(16);
    cout << a << endl << b << endl;
    return 0;
}