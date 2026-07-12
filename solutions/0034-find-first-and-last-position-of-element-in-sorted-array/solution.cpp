class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int n= nums.size();
        for(int i=0; i<n ;i++){
            if(nums[i] == target){
                ans.push_back(i);
                continue;
            }
        }
        if (ans.size() > 2) {
            ans.erase(ans.begin() + 1, ans.end() - 1);
        } else if(ans.size() == 1){
            ans.push_back(ans[0]);
        }
        
        vector<int>fail(2, -1);
        if(!ans.empty()) return ans;
        return fail;
    }
};
