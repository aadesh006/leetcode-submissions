class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(nums[i] != i) return i;
            else if(nums[n-1] == i) return i+1;
        }
        return 0;
    }
};
