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
    int dfs(TreeNode* current, int& cameraCount){
        if(!current) return 2;

        int leftChild = dfs(current->left, cameraCount);
        int rightChild = dfs(current->right, cameraCount);

        if(leftChild == 0 || rightChild == 0){
            cameraCount++;
            return 1;
        }

        if(leftChild ==1 || rightChild ==1) return 2;
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        int cameraCount=0;
        if(dfs(root, cameraCount) == 0) cameraCount++;
        return cameraCount;
    }
};
