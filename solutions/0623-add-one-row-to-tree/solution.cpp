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
    void Traverse(TreeNode* current, int val, int depth, int k){
        if(!current) return;

        if(k == depth -1){
            TreeNode* oldLeft = current->left;
            TreeNode* oldRight = current->right;

            current->left = new TreeNode(val);
            current->right = new TreeNode(val);

            current->left->left = oldLeft;
            current->right->right = oldRight;
            return; 
        }
        Traverse(current->left, val, depth, k+1);
        Traverse(current->right, val, depth, k+1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return nullptr;
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        TreeNode* current = root;
        Traverse(current, val, depth, 1);
        return root;
    }
};
