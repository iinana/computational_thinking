#include <iostream>
using namespace std;

int max_robber(int* nums) {
    int size = sizeof(nums);
    if (size <= 0) return 0;
    else if (size == 1) return nums[0];
    else if (size == 2) {
        return ((nums[0] > nums[1]) ? nums[0] : nums[1]);
    }

    int pp = nums[0];
    int p = ((nums[0] > nums[1]) ? nums[0] : nums[1]);
    for (int i = 2; i <= size; i++) {
        if (p >= nums[i] + pp) pp = p;
        else {
            int temp = p;
            p = nums[i] + pp;
            pp = temp;
        }
    }
    return p;
}

int main() {
    int nums[] = {3, 7, 8, 2, 1};
    cout << max_robber(nums) << endl;
}