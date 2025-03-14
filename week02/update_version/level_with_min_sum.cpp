#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <deque>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree {
public:
    TreeNode* root;
    Tree(unordered_map<int, int>& dic) {
        int i_root = 0;
        if (dic.find(i_root) == dic.end()) {
            cerr << "Error: no root id" << endl;
            exit(1);
        }
        root = new TreeNode(dic[i_root]);
        queue<pair<int, TreeNode*> > q;
        q.push(make_pair(i_root, root));
        int i_curr, i_left, i_right;
        TreeNode* curr;
        TreeNode* child;
        pair<int, TreeNode*> p;
        while (!q.empty()) {
            p = q.front(); q.pop();
            i_curr = p.first;
            curr = p.second;
            i_left = i_curr * 2 + 1; 
            if (dic.find(i_left) != dic.end()) {
                child = new TreeNode(dic[i_left]);
                q.push(make_pair(i_left, child));
                curr->left = child;
            }
            i_right = i_curr * 2 + 2;
            if (dic.find(i_right) != dic.end()) {
                child = new TreeNode(dic[i_right]);
                q.push(make_pair(i_right, child));
                curr->right = child;
            }
        }
    }
};

int level_with_min_sum(TreeNode* root) {
    deque<TreeNode*> q;
    q.push_back(root);
    int min_sum = root->val;
    int min_lev = 0;
    int cur_lev = 0;

    while (!q.empty()) {
        int init_size = q.size();
        int sum = 0;
        for (int i = 0; i < init_size; i++) {
            if (q.front()->left) q.push_back(q.front()->left);
            if (q.front()->right) q.push_back(q.front()->right);
            sum += q.front()->val;
            q.pop_front();
        }

        if (sum < min_sum) {
            min_sum = sum;
            min_lev = cur_lev;
        }
        cur_lev++;
    }

    return min_lev;
}

int main() {
    unordered_map<int, int> nodes = {{0, 9}, {1, 2}, {2, 3}, {5, 1}, {6, 5}};
    Tree t(nodes);
    int result = level_with_min_sum(t.root);
    cout << result << endl;
}
