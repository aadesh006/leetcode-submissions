class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<std::vector<int>> res;
        vector<int> currentComb;
        sort(candidates.begin(), candidates.end());
        
        backtrack(0, candidates, target, currentComb, res);
        return res;
    }

private:
    void backtrack(int start, const vector<int>& candidates, int target, 
    vector<int>& currentComb, vector<vector<int>>& res) {

        if (target == 0) {
            res.push_back(currentComb);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;

            currentComb.push_back(candidates[i]);
            backtrack(i, candidates, target - candidates[i], currentComb, res);
            currentComb.pop_back();
        }
    }
};

