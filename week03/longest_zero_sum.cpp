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

int longest_zero_sum(const vector<int>& arr) {
    unordered_map<int, Location> sum_map;

    int prefix_sum = arr[0];
    if (arr[0] == 0) sum_map.insert(make_pair(prefix_sum, Location(-1, 0)));
    else sum_map.insert(make_pair(prefix_sum, Location(0, 0)));
    
    for (int i = 1; i < arr.size(); i++) {
        prefix_sum += arr[i];
        if (prefix_sum == 0 && sum_map.count(0) == 0) {
            sum_map.insert(make_pair(prefix_sum, Location(-1, i)));
        } else if (sum_map.count(prefix_sum) > 0) 
            sum_map[prefix_sum].end = i; 
        else sum_map.insert(make_pair(prefix_sum, Location(i, i)));
    }

    int max = 0;
    for (unordered_map<int, Location>::iterator iter = sum_map.begin(); iter != sum_map.end(); ++iter) {
        int curr = iter->second.end - iter->second.start;
        if (curr > max) max = curr;
    }

    return max;
    
}

void test() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    // input: {15, -2, 2, -8, 1, 7, 10, 23}
    // output: 5
    int n = longest_zero_sum(arr);
    cout << n << endl; 
}

int main() {
    test();
    return 0;
}

