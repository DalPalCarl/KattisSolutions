#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, a, b, temp;
    cin >> n;
    
    a = (int) n / 10;
    b = n - (a * 10);
    
    cout << b << a << endl;
    return 0;
}