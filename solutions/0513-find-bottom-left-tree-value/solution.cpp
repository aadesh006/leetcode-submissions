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
    int maxDepth =-1;
    int bottomVal =0;
private:
    void dfs(TreeNode* node, int currentDepth){
        if(!node) return;

        if(currentDepth > maxDepth){
            maxDepth = currentDepth;
            bottomVal = node->val;
        }

        dfs(node->left, currentDepth+1);
        dfs(node->right, currentDepth+1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        maxDepth =-1;
        dfs(root, 0);
        return bottomVal;
    }
};
