#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

bool recur_robot(int x, int y, vector<vector<int>>& grid, vector<pair<int, int>>& res) {
    if (x == grid.size()-1 && y == grid[0].size()-1) {
        if (grid[x][y] == 1) return false;
        res.push_back(make_pair(x, y));
        return true;
    }

    if (grid[x][y] == 1) return false;
    else {
        if ((x + 1) < grid.size() && recur_robot(x+1, y, grid, res)) {
            res.insert(res.begin(), make_pair(x, y));
            return true;
        } else if ((y + 1) < grid.size() && recur_robot(x, y+1, grid, res)) {
            res.insert(res.begin(), make_pair(x, y));
            return true;
        } else {
            grid[x][y] = 1;
            return false;
        }
    }
}

vector<pair<int, int>> robot(vector<vector<int>>& grid) {
    vector<pair<int, int>> res;
    if (recur_robot(0, 0, grid, res)) return res;
    else {
        res.clear();
        return res;
    }
}

void print_path(vector<pair<int, int>>& path) {
    if (path.empty()) {
        cout << "None" << endl;
    } else {
        vector<pair<int, int>>::iterator it;
        cout << "[";
        for (it = path.begin(); it != path.end(); ++it) {
            cout << "(" << it->first << ", " << it->second << ")";
            if (next(it) != path.end())
                cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main(int argc, char* argv[]) {
    // Example 1
    vector<vector<int>> grid1 = {
        {0, 0, 1, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 0}
    };
    cout << "Example 1:" << endl;
    vector<pair<int, int>> path1 = robot(grid1);
    print_path(path1);

    // Example 2
    vector<vector<int>> grid2 = {
        {0, 0, 1, 1},
        {1, 0, 1, 1},
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    cout << "Example 2:" << endl;
    vector<pair<int, int>> path2 = robot(grid2);
    print_path(path2);

    return 0;
}

