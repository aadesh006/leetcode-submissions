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
    void dfsHelper(TreeNode* root, int row, int col, vector<tuple<int,int,int>>& nodes){
        if(!root) return;
        nodes.emplace_back(col, row, root->val);
        dfsHelper(root->left, row+1, col-1, nodes);
        dfsHelper(root->right, row+1, col+1, nodes);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>>nodes;
        dfsHelper(root, 0, 0, nodes);

        sort(nodes.begin(), nodes.end());
        vector<vector<int>> result;
        int prevCol = INT_MIN;

        for(auto[col, row, val] : nodes){
            if(col != prevCol){
                result.push_back({});
                prevCol = col;
            }
            result.back().push_back(val);
        }
        return result;
    }
};
