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
    void dfs(TreeNode* current, string currentPath,vector<string>& leafNodes){
        if(!current) return;

        currentPath += to_string(current->val);

        if (!current->left && !current->right) {
            leafNodes.push_back(currentPath);
            return;
        }
        dfs(current->left, currentPath, leafNodes);
        dfs(current->right, currentPath, leafNodes);
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<string> leafNodes;
        dfs(root, "", leafNodes);

        int totalSum = 0;
        for (const string& path : leafNodes) {
            totalSum += stoi(path);
        }

        return totalSum;
    }
};
