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
};

void level_order_print(TreeNode* root) {
    deque<TreeNode*> level;
    cout << root->data << " ";
    level.push_back(root);

    while (!level.empty()) {
        TreeNode* curr = level.front();
        level.pop_front();

        if (curr->left) {
            cout << curr->left->data << " ";
            level.push_back(curr->left);
        }
        if (curr->right) {
            cout << curr->right->data << " ";
            level.push_back(curr->right);
        }
    } 
    cout << endl;
}

void preorder_print(TreeNode* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorder_print(root->left);
    preorder_print(root->right);
}

void inorder_print(TreeNode* root) {
    if (root == nullptr) return;

    inorder_print(root->left);
    cout << root->data << " ";
    inorder_print(root->right);
}

void postorder_print(TreeNode* root) {
    if (root == nullptr) return;

    postorder_print(root->left);
    postorder_print(root->right);
    cout << root->data << " ";
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
    level_order_print(t.root);
    preorder_print(t.root);
    cout << endl;
    inorder_print(t.root);
    cout << endl;
    postorder_print(t.root);
}