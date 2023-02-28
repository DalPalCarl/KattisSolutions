#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector<int> nums, final;
    vector<char> letters;
    
    for(int i = 0; i < 3; i++){
        int n;
        cin >> n;
        nums.push_back(n);
    }
    
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for(int i = 0; i < 2; i++){
            if(nums[i+1] < nums[i]){
                int temp = nums[i+1];
                nums[i+1] = nums[i];
                nums[i] = temp;
                sorted = false;
            }
        }
    }
    
    for(int i = 0; i < 3; i++){
        char c;
        cin >> c;
        letters.push_back(c);
    }
    
    for(int j = 0; j < 3; j++){
        switch(letters[j]){
            case 'A':
                final.push_back(nums[0]);
                break;
            case 'B':
                final.push_back(nums[1]);
                break;
            case 'C':
                final.push_back(nums[2]);
                break;
        }
    }
    
    for(int i = 0; i < 3; i++){
        cout << final[i] << " ";
    }
    cout << endl;
    
    return 0;
}
