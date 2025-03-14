#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// max_level mutable 로 바꿔야 함! (다시 root로 돌아갔을 때 반영 안되기 때문)
void helper(TreeNode* root, int cur_level, int max_level, vector<int>& output) {
    if (root == nullptr) return;
    if (cur_level > max_level) {
        output.push_back(root->val);
        max_level = cur_level;
    }

    helper(root->right, cur_level+1, max_level, output);
    helper(root->left, cur_level+1, max_level, output);
}

vector<int> right_side_view(TreeNode* root) {
    vector<int> output;
    int max_level = -1;
    helper(root, max_level, 0, output);
    return output;
}

/* given the root of a binary tree, imagine yourself standing on the right side of it, 
    return the values of nodes you can see ordered from top to bottom*/
// O(h) time, O(n) space