#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

class TreeNode {
    public:
        char data;
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

TreeNode* recursive_struct(vector<char>& preorder, unordered_map<char, int> in_map, int pre_start, int pre_end, int in_start, int in_end) {
    if (pre_start > pre_end || in_start > in_end)
        return nullptr;

    char r = preorder[pre_start];
    int pivot = in_map[r];

    TreeNode* root = new TreeNode(r);
    root->left = recursive_struct(preorder, in_map, pre_start + 1, pre_start + pivot - in_start, in_start, pivot - 1);
    root->right = recursive_struct(preorder, in_map, pre_start + pivot - in_start + 1, pre_end, pivot + 1, in_end);
    return root;
}

TreeNode* reconstructTree(vector<char>& preorder, vector<char>& inorder) {
    unordered_map<char, int> in_map;
    for (int i = 0; i < inorder.size(); i++) {
        in_map.insert(make_pair(inorder[i], i));
    }
    
    return (recursive_struct(preorder, in_map, 0, preorder.size() - 1, 0, inorder.size() - 1));
}

int main() {
    vector<char> preorder = {'a', 'b', 'd', 'e', 'c', 'f', 'g'};
    vector<char> inorder = {'d', 'b', 'e', 'a', 'f', 'c', 'g'};
    TreeNode* root = reconstructTree(preorder, inorder);
    Tree t(root);
    t.print_tree();
}