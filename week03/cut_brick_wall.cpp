#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int fewest_number(vector<vector<int>>& bricks) {
    int width = 0;
    for (int i : bricks[0]) width += i;

    // initialize all the elements of cut_point array as 0
    int* cut_point = new int[width + 1];
    for (int i = 0; i <= width; i++)
        cut_point[i] = 0;

    // count the lines alredy cut
    for (vector<int> v : bricks) {
        int loc = 0;
        for (int i : v) {
            loc += i;
            cut_point[loc]++;
        }
    }

    // find the maximum value
    int max = 0;
    for (int i = 1; i < width; i++) {
        if (cut_point[i] > max)
            max = cut_point[i];
    }
    
    // return the remainings (will be cut)
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
