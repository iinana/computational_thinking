#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int k) : data(k), left(nullptr), right(nullptr) {}
        TreeNode(int k, TreeNode* l, TreeNode* r) : data(k), left(l), right(r) {}
};

class Tree {
    public:
        TreeNode* root;
        Tree() : root(nullptr) {}
        Tree(TreeNode* r) : root(r) {}
        void print_tree();
};

void Tree::print_tree() {
    deque<TreeNode*> level_order;
    level_order.push_back(root);
    while (level_order.front() != nullptr) {
        int origin_len = level_order.size();
        for (int i = 0; i < origin_len; i++) {
            cout << level_order.front()->data << " ";
            level_order.push_back(level_order.front()->left);
            level_order.push_back(level_order.front()->right);
            level_order.pop_front();
        }
        cout << endl;
    }
}

TreeNode* recursive_tree(vector<int>&arr, int start, int end) {
    if (start > end) 
        return nullptr;
    int mid = (start + end) / 2;
    return new TreeNode(arr[mid], recursive_tree(arr, start, mid - 1), recursive_tree(arr, mid + 1, end));
}

TreeNode* minimalTree(vector<int>& arr) {
    return recursive_tree(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {2, 3, 4, 6, 7, 8, 9};
    TreeNode* root = minimalTree(arr);
    Tree t(root);
    t.print_tree();
}