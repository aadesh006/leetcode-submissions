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
    void dfs(TreeNode* current, string path, vector<string>& result) {
        if (!current) return;
        if (!path.empty()) path += "->";
        path += to_string(current->val);

        if (!current->left && !current->right) {
            result.push_back(path);
            return;
        }

        dfs(current->left, path, result);
        dfs(current->right, path, result);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};
 
