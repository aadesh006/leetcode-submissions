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
    int dfs(TreeNode* node){
        if(!node) return 0;
        if(node && !node->left && !node->right) return 1;

        int left = INT_MAX, right =INT_MAX;

        if(node->left) left = 1+ dfs(node->left);
        if(node->right) right = 1+ dfs(node->right);

        return min(left, right);
    }
public:
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};
