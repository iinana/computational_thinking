#include <iostream>
#include <vector>
using namespace std;

vector<int> moving_grid(vector<vector<int>> grid) {
    int x = grid.size();
    int y = grid[0].size();

    vector<vector<int>> cost_table(x, vector<int>(y, 0));
    vector<vector<char>> arrow_table(x, vector<char>(y, 0));
    for (int j = 0; j < y; j++) {
        cost_table[0][j] = grid[0][j];
    }

    for (int i = 1; i < x; i++) {
        for (int j = 0; j < y; j++) {
            int min = cost_table[i-1][j];
            arrow_table[i][j] = 'd'; // down as 'd'
            if (j-1 >= 0 && cost_table[i-1][j-1] < min) {
                min = cost_table[i-1][j-1];
                arrow_table[i][j] = 'l'; // left as 'l'
            }
            if (j+1 < y && cost_table[i-1][j+1] < min) {
                min = cost_table[i-1][j+1];
                arrow_table[i][j] = 'r'; // right as 'r'
            }
            cost_table[i][j] = min + grid[i][j];
        }
    }

    int min_loc = 0;
    for (int j = 1; j < y; j++) {
        if (cost_table[x-1][min_loc] > cost_table[x-1][j])
            min_loc = j;
    }

    vector<int> res;
    for (int i = x - 1; i >= 0; i--) {
        res.insert(res.begin(), min_loc);
        if (arrow_table[i][min_loc] == 'l') min_loc--;
        else if (arrow_table[i][min_loc] == 'r') min_loc++;
    }
    return res;
}

int main() {
    vector<vector<int>> grid = {
        {3, 2, 5, 4, 8},
        {5, 7, 5, 6, 1},
        {4, 4, 6, 2, 3},
        {2, 8, 9, 5, 8}
    };

    vector<int> res = moving_grid(grid);
    for (int i : res) cout << i << " ";
    cout << endl;
}

