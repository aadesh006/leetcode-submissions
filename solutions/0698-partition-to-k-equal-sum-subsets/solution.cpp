class Solution {
private:
    bool backtrack(int idx, int k, int subsetSum, int target, vector<int>& nums, vector<bool>& used){
        if(k ==0) return true;

        if(subsetSum == target)
            return backtrack(0, k-1, 0, target, nums, used);
        
        for(int i=idx; i<nums.size(); i++){
            if(used[i] || subsetSum +nums[i]>target) continue;
            used[i]=true;

            if(backtrack(i+1, k, subsetSum+nums[i], target, nums, used)) return true;
            used[i]=false;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int arrSum=0;
        for(int num :nums) arrSum +=num;
        if(arrSum%k != 0) return false;
        int target = arrSum/k;
        sort(nums.rbegin(), nums.rend());
        vector<bool>used(nums.size(), false);
        return backtrack(0, k, 0, target,nums, used);
    }
};
