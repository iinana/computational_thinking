#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int fewest_number(vector<vector<int>>& bricks) {
    unordered_map<int, int> edges;
    for (vector<int> row : bricks) {
        int length = 0;
        for (int i = 0; i < row.size()-1; i++) {
            length += row[i];
            if (edges.count(length) > 0)
                edges[length]++;
            else edges.insert(make_pair(length, 1));
        }
    }

    int max = 0;
    for (unordered_map<int, int>::iterator itr = edges.begin(); itr != edges.end(); ++itr) {
        if (itr->second > max)
            max = itr->second;
    }
    return (bricks.size() - max);
}

void test() {
    int height = 6;
    vector<vector<int>> bricks = {
        {3, 5, 1, 1}, {2, 3, 3, 2}, {5, 5}, {4, 4, 2}, {1, 3, 3, 3}, {1, 1, 6, 1, 1}
    };
    int n = fewest_number(bricks);
    cout << n << endl;
    // The output n for the above example is 2.
}

int main() {
    test();
    return 0;
}
