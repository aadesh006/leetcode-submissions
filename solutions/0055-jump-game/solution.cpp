class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal =0;
        int n = nums.size();

        for(int i =0; i<n; i++){
            if(i>goal) return false;

            goal = max(goal, i+nums[i]);
            if(goal >= n-1) return true;
        }
        return false;
    }
};
