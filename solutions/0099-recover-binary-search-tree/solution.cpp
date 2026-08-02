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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void dfs(TreeNode* current) {
        if (!current) return;

        dfs(current->left);
        if (prev && prev->val > current->val) {
            if (!first) first = prev;
            second = current;
        }
        prev = current;
        dfs(current->right);
    }

public:
    void recoverTree(TreeNode* root) {
        dfs(root);
        if (first && second) swap(first->val, second->val);
    }
};

