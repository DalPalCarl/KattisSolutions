#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    int n;
    double q, y;
    
    cin >> n;
    double qual;
    for(int i = 0; i < n; i++){
        cin >> q >> y;
        qual += q * y;
    }
    
    cout << setprecision(6);
    cout << qual << endl;
    return 0;
}