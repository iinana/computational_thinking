#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<vector<int>>& res, vector<int> cur, vector<int>& candidates, int start, int target) {
    if (target == 0) {
        for (vector<int> v : res) {
            if (v == cur) return;
        }
        res.push_back(cur);
        return;
    } else if (target < 0) return;

    for (int i = start; i < candidates.size(); i++) {
        if (candidates[i] <= target) {
            cur.push_back(candidates[i]);
            backtrack(res, cur, candidates, i+1, target-candidates[i]);
            cur.pop_back();
        }
    }
}

vector<vector<int>> combination_sum(vector<int>& candidates, int target) {
    vector<vector<int>> res = {};
    backtrack(res, {}, candidates, 0, target);
    return res;
}

void print_answers(vector<vector<int>> ans) {
    cout << "[";
    for (int j = 0; j < ans.size(); j++) {
        cout << "[";
        for (int i = 0; i < ans[j].size(); i++) {
            cout << ans[j][i];
            if (i < ans[j].size()-1) cout << ", ";
        }
        cout << "]";
        if (j < ans.size()-1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    // Example 1
    vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;
    cout << "Example 1" << endl;
    cout << "candidates: ";
    sort(candidates1.begin(), candidates1.end());
    for (int i = 0; i < candidates1.size(); i++) {
        cout << candidates1[i];
        if (i < candidates1.size() - 1)
            cout << ", ";
    }
    cout << endl;
    cout << "target: " << target1 << endl;
    vector<vector<int>> ans1 = combination_sum(candidates1, target1);
    cout << "ans: ";
    print_answers(ans1);
    cout << "**************************************************" << endl;

    // Example 2
    vector<int> candidates2 = {2, 5, 2, 1, 2};
    int target2 = 5;
    cout << "Example 2" << endl;
    cout << "candidates: ";
    sort(candidates2.begin(), candidates2.end());
    for (int i = 0; i < candidates2.size(); i++) {
        cout << candidates2[i];
        if (i < candidates2.size() - 1)
            cout << ", ";
    }
    cout << endl;
    cout << "target: " << target2 << endl;
    vector<vector<int>> ans2 = combination_sum(candidates2, target2);
    cout << "ans: ";
    print_answers(ans2);
    
    return 0;
}

