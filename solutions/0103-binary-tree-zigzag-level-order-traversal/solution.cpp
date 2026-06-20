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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool directionFlag = true;

        while(!q.empty()){
            vector<int> currentLevel;
            int levelSize = q.size();

            for(int i=0; i<levelSize; i++){
                TreeNode* temp = q.front();
                q.pop();

                currentLevel.push_back(temp->val);

                if(temp->left != nullptr) q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);

            }

            if (!directionFlag) {
                reverse(currentLevel.begin(), currentLevel.end());
            }
            
            result.push_back(currentLevel);
            directionFlag = !directionFlag;
        }

        return result;
    }
};
