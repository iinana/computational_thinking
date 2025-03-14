#include <iostream>
#include <vector>
using namespace std;

bool is_valid(vector<int> locations, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (locations[i] == col) return false;
        if (locations[i] == col - (row-i) || locations[i] == col + (row-i)) return false;
    }
    return true;
}

void n_queens_recur(vector<int> locations, int n , int row, int& count) {
    if (row == n) {
        count++;
        for (int i : locations) cout << i;
        cout << endl;
        return;
    }

    locations.push_back(0);
    for (int i = 0; i < n; i++) {
        if (row == 0 || is_valid(locations, row, i)) {
            locations[row] = i;
            n_queens_recur(locations, n, row+1, count);
        }
    }
}

// count the number of solutions to place the N queens on the board
int n_queens(int n) {
    int count = 0;
    if (n <= 1) return n;
    n_queens_recur(vector<int>(), n, 0, count);
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << n_queens(n) << endl;
}