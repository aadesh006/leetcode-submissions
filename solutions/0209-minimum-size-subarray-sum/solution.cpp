class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int lenSubArr = INT_MAX;
        int currentSum = 0;

        for(int right = 0; right<nums.size(); right++){
            currentSum += nums[right];

            while(currentSum >= target){
                lenSubArr = min(lenSubArr, right-left+1);
                currentSum -= nums[left];
                left++;
            }
        }

        return (lenSubArr == INT_MAX) ? 0 : lenSubArr;
    }
};
