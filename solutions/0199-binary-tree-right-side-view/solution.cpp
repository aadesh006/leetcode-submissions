/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    void dfs(TreeNode* node, int depth, vector<int>& viewVector) {
        if (!node) return;
        if (depth == viewVector.size()) {
            viewVector.push_back(node->val);
        }
        dfs(node->right, depth + 1, viewVector);
        dfs(node->left, depth + 1, viewVector);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> viewVector;
        dfs(root, 0, viewVector);
        return viewVector;
    }
};

