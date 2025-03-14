#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// bool twoSum(vector<int>& nums, int k) {
//     unordered_map<int, bool> h;
//     for (int i : nums) {
//         h.insert(make_pair(i, true));
//     }

//     for (int i = 0; i <= k / 2; i++) {
//         if (i != (k - i) && h.count(i) > 0 && h.count(k - i) > 0)
//             return true;
//     }
//     return false;
// }

bool twoSum(vector<int>& nums, int k) {
    unordered_map<int, bool> visited;
    for (int i : nums) {
        if (visited.count(k - i) > 0)
            return true;
        visited.insert(make_pair(i, true));
    }
    return false;
}

int main() {
    vector<int> nums = {5, 3, 10, 12, 9};
    int k = 19;

    bool res = twoSum(nums, k);
    if (res) cout << "true" << endl;
    else cout << "false" << endl;
}