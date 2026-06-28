class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> multiply(k);
        for(int i=0; i<k; i++){
            multiply[i] = max(1LL, (long long)mul-i);
        }

        sort(multiply.begin(), multiply.end());
        long long maxSum =0;
        for(int i=0; i<k;i++){
            maxSum +=(long long)nums[n-k+i]*multiply[i];
        }
        return maxSum;
    }
};
