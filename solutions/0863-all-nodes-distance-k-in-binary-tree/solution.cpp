/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool findTarget(TreeNode* current, TreeNode* target, vector<TreeNode*>&path){
        if(!current) return false;

        path.push_back(current);
        if(current == target) return true;

        if(findTarget(current->left, target, path) || findTarget(current->right, target, path)) return true;

        path.pop_back();
        return false;
    }
    void countKNode(TreeNode* current, TreeNode* block, int depth, vector<int>& result){
        if(!current || current == block) return;
        if(depth == 0){
            result.push_back(current->val);
            return;
        }
        countKNode(current->left, block, depth-1, result);
        countKNode(current->right, block, depth-1, result);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path;
        vector<int>result;

        findTarget(root, target, path);
        TreeNode* block = nullptr;
        for(int i= path.size()-1; i>=0; i--){
            TreeNode* currentAncestor = path[i];
            countKNode(currentAncestor, block, k, result);
            k--;
            block=currentAncestor;
            if(k < 0) break;
        }
        return result;
    }
};
