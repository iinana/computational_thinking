#include <iostream>
#include <vector>
using namespace std;

// time complexity = O(n)
// space complexity = O(1)
// using linear search
int num_common(vector<int>& a, vector<int> b) {
    int b_loc = 0;
    int res = 0;

    for (int i = 0; i < a.size(); i++) {
        while (b_loc < b.size() && b[b_loc] < a[i]) b_loc++;
        if (b_loc == b.size()) break;
        if (b[b_loc] == a[i]) res++;
    }

    return res;
}

int main() {
    vector<int> a = {13, 27, 35, 40, 49, 55, 59};
    vector<int> b = {17, 35, 39, 40, 55, 58, 60};
    cout << num_common(a, b) << endl;  // 3
}