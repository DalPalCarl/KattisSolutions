#include <iostream>
using namespace std;
int main(){
    int n, c, k;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> c >> k;
        int total = k;
        for(int j = 1; j <= k; j++){
            total += j;
        }
        cout << c << " " << total << endl;
    }
    return 0;
}