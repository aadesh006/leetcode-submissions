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
    int preIdx = 0; 
    unordered_map<int, int> inMap;
private:
    TreeNode* constructTree(vector<int>& preorder, int left, int right){
        if(left > right) return nullptr;
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inMap[rootVal];
        root->left = constructTree(preorder, left, mid - 1);
        root->right = constructTree(preorder, mid + 1, right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIdx = 0;
        inMap.clear();
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i; 
        }
        return constructTree(preorder, 0, inorder.size() - 1);
    }
};

