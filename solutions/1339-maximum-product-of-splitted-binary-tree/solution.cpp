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
    long long calculateSubTree(TreeNode* root, vector<long long>& totalSum){
        if(root == nullptr) return 0;

        long long currentSum = root->val
                               +calculateSubTree(root->left, totalSum)
                               +calculateSubTree(root->right, totalSum);
        
        totalSum.push_back(currentSum);
        return currentSum;
    }
public:
    int maxProduct(TreeNode* root) {
        vector<long long> allSum;

        long long totalSum = calculateSubTree(root, allSum);
        const int MOD = 1e9 + 7;
        long long maxValue = 0;

        for(long long subTreeSum : allSum){
            long long remainingSum = totalSum - subTreeSum;
            long long currentProduct = subTreeSum * remainingSum;

            maxValue = max(maxValue, currentProduct);
        }
        return maxValue%MOD;
    }
};
