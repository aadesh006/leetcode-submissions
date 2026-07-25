class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if (nums.empty()) return 0;

        int currentMax = nums[0];
        int globalMax = nums[0];
        int currentMin = nums[0];
        int globalMin = nums[0];
        int totalSum = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            totalSum += nums[i];
            currentMax = max(nums[i], currentMax + nums[i]);
            globalMax = max(globalMax, currentMax);

            currentMin = min(nums[i], currentMin+nums[i]);
            globalMin = min(globalMin, currentMin);
        }
        if (globalMax < 0) return globalMax;

        return max(globalMax, totalSum-globalMin);
    }
};
