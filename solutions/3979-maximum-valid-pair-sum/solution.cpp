class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int maxLeft = INT_MIN;
        int index =0;

        for(int i=0; i<n;i++){
            while(index<=i-k){
                maxLeft=max(maxLeft,nums[index]);
                index++;
            }
            maxSum=max(maxSum, maxLeft+nums[i]);
        }
    return maxSum;
    }
};
