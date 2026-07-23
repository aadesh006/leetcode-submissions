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
    int dfs(TreeNode* current, int& count){
        if(!current) return INT_MIN;

        int left = dfs(current->left, count);
        int right = dfs(current->right, count);

        if (current->val >=left && current->val >=right) count++;

        return max({current->val, left, right});
    }
public:
    int countDominantNodes(TreeNode* root) {
        int count=0;
        dfs(root, count);
        return count;
    }
};
