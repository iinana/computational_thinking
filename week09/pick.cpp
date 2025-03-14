#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int pick(const vector<int>& nums, int target) {
    vector<int> idxs;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) idxs.push_back(i); 
    }

    return idxs[rand() % idxs.size()];
}

int main() {
    srand(time(0)); // Seed the random number generator
    vector<int> nums = {1, 2, 3, 3, 3};
    int target = 3;
    
    int output = pick(nums, target);
    cout << output << endl; 

    return 0;
    // The output for the above example is 0.
}
