#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, x, total;
    total = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        total += x;
    }
    
    cout << total - (n-1) << endl;
    
    return 0;
}