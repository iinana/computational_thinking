#include <iostream>
#include <vector>
using namespace std;

// 0 none, 1 obstacle, 2 visited
void robot(vector<vector<int>>& grid, int row, int col) {
    if (row < 0 || row >= grid.size()) return;
    if (col < 0 || col >= grid[0].size()) return;
    if (grid[row][col] != 0) return;
    
    grid[row][col] = 2;
    cout << '(' << row << "," << col << ") ";
    robot(grid, row, col+1);
    robot(grid, row-1, col);
    robot(grid, row, col-1);
    robot(grid, row+1, col);

    cout << '(' << row << "," << col << ") ";
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 1, 1, 1, 1}, 
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    robot(grid, 1, 3);
}