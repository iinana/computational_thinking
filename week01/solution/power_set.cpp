#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> power_set_recursive(vector<int>& A, int end) {
    if (end < 0) return {{}};
    else {
        vector<vector<int>> sets = power_set_recursive(A, end-1);
        int sets_size = sets.size();
        for (int i = 0; i < sets_size; i++) {
            vector<int> newElem = sets[i];
            newElem.push_back(A[end]);
            sets.push_back(newElem); 
        }
        return sets;
    }
}

vector<vector<int>> power_set_iterative(vector<int>& A) {
    vector<vector<int>> sets;
    sets.push_back({});
    for (int n : A) {
        int sets_size = sets.size();
        for (int i = 0; i < sets_size; i++) {
            vector<int> newElem = sets[i];
            newElem.push_back(n);
            sets.push_back(newElem);
        }
    }
    return sets;
}

int main(int argc, char* argv[]) {
    vector<int> lst;
    for (int i = 1; i < argc; i++) {
        lst.push_back(atoi(argv[i]));
    }

    vector<vector<int>> res = power_set_recursive(lst, lst.size()-1);
    for (vector<int> v : res) {
        cout << "[ ";
        for (int n : v) cout << n << " ";
        cout << "] ";
    }
}