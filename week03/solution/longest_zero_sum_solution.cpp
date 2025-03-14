#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Location {
    public:
        int start;
        int end;
        Location() {}
        Location(int s, int e) : start(s), end(e) {}
};

int longest_zero_sum_naive(const vector<int>& arr) {
    int maxLen = 0;
    for (int i = 0; i < arr.size(); i++) {
        int currSum = 0;
        for (int j = i; j < arr.size(); j++) {
            currSum += arr[j];
            if (currSum == 0 && maxLen < (j - i + 1))
                maxLen = j - i + 1;
        }
    }
    return maxLen;
}

int longest_zero_sum(const vector<int>& arr) {
    unordered_map<int, int> h;
    int maxLen = 0;
    int prefixSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];
        if (h.count(prefixSum) > 0 && maxLen < (i - h[prefixSum])) {
            maxLen = i - h[prefixSum];
        } else h[prefixSum] = i;
    }
    return maxLen;
}

void test() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    // input: {15, -2, 2, -8, 1, 7, 10, 23}
    // output: 5
    int n = longest_zero_sum_naive(arr);
    cout << n << endl; 
}

int main() {
    test();
    return 0;
}