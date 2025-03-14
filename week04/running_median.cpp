#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<double> running_median(vector<int>& nums) {
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    vector<double> median;
    if (nums.size() <= 0)
        return median;

    median.push_back(nums[0]);
    maxq.push(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] <= median[i - 1]) {
            maxq.push(nums[i]);
            if (maxq.size() > (minq.size() + 1)) {
                minq.push(maxq.top());
                maxq.pop();
            }     
        } else {
            minq.push(nums[i]);
            if (minq.size() > (maxq.size() + 1)) {
                maxq.push(minq.top());
                minq.pop();
            } 
        }

        if (maxq.size() == minq.size()) {
            median.push_back((maxq.top() + minq.top()) / 2.0);
        } else if (maxq.size() > minq.size()) {
            median.push_back(maxq.top());
        } else median.push_back(minq.top());
    }

    return median;
}

int main() {
    vector<int> nums = {2, 1, 5, 7, 9, 11, 13};

    vector<double> n = running_median(nums);

    for (double med : n) {
        cout << med << " ";
    }
    cout << endl;

    return 0;
    // The output n for the above example is 2 1.5 2 3.5 2 2 2.
}