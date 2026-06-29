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
    unsigned long long maxWidth =0;
    vector<long long> firstIndex;
private:
    void dfs(TreeNode* node, int depth, unsigned long long currentIndex){
        if(!node) return;

        if(depth == firstIndex.size()){
            firstIndex.push_back(currentIndex);
        }

        unsigned long long newIndex = currentIndex - firstIndex[depth];
        maxWidth = max(maxWidth, newIndex+1);

        dfs(node->left, depth+1, 2*currentIndex);
        dfs(node->right, depth+1, 2*currentIndex + 1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        maxWidth =0;
        firstIndex.clear();
        dfs(root, 0, 0);
        return maxWidth;
    }
};
