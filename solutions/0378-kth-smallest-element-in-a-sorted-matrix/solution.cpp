class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> ans;
        for (const auto& row : matrix) {
            for (int val : row) {
                ans.push_back(val);
            }
        }
        sort(ans.begin(), ans.end());
        return ans[k-1]; 
    }
};

