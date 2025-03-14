#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> power_set(vector<int>& A) {
    vector<vector<int>> res;

    int res_size;
    res.push_back({});

    for (int a : A) {
        res_size = res.size();
        for (int i = 0; i < res_size; i++) {
            vector<int> temp = res[i];
            temp.push_back(a);
            res.push_back(temp);
        }
    }

    return res;
}

int main(int argc, char* argv[]) {
    vector<int> lst;
    for (int i = 1; i < argc; i++) {
        lst.push_back(atoi(argv[i]));
    }

    vector<vector<int>> res = power_set(lst);
    for (vector<int> v : res) {
        cout << "[ ";
        for (int n : v) cout << n << " ";
        cout << "] ";
    }
}