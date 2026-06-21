class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;

        int currentMax = nums[0];
        int globalMax = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            currentMax = max(nums[i], currentMax + nums[i]);
            globalMax = max(globalMax, currentMax);
        }

        return globalMax;
    }
};

