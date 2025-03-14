#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
// int bowling(vector<int>& nums) {
//     vector<int> add_table(nums.size());
//     vector<int> mul_table(nums.size());

//     add_table[0] = (nums[0] > 0) ? nums[0] : 0;
//     mul_table[0] = 0;
//     for (int i = 1; i < nums.size(); i++) {
//         add_table[i] = (add_table[i-1] > mul_table[i-1]) ? add_table[i-1] : mul_table[i-1];
//         if (i-2 < 0) mul_table[i] = 0;
//         else mul_table[i] = (add_table[i-2] > mul_table[i-2]) ? add_table[i-2] : mul_table[i-2]; 

//         if (nums[i] > 0) add_table[i] += nums[i];
//         if (nums[i] * nums[i-1] > 0) mul_table[i] += nums[i] * nums[i-1];
//     }

//     if (add_table[nums.size()-1] > mul_table[nums.size()-1])
//         return add_table[nums.size()-1];
//     else return mul_table[nums.size()-1];
// }

int bowling(vector<int>& nums) {
    int p_bigger = 0;
    int pp_bigger = 0;
    int add_curr, mul_curr;
    for (int i = 0; i < nums.size(); i++) {
        add_curr = p_bigger;
        mul_curr = pp_bigger;

        if (nums[i] > 0) add_curr += nums[i];
        if (nums[i] * nums[i-1] > 0) mul_curr += nums[i] * nums[i-1];

        pp_bigger = p_bigger;
        p_bigger = (add_curr > mul_curr) ? add_curr : mul_curr;
    }

    return p_bigger;
}

int main() {
    vector<int> nums = {-3, 1, 1, 9, 9, 2, -5, -5};

    int out = bowling(nums);
    cout << "Result from bowling function: " << out << endl;

    return 0;
}

