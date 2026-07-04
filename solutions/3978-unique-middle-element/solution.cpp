class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int middle = nums[n/2];
        int count =0;

        for(int i: nums){
            if(i==middle) count++;
        }

        if(count ==1) return true;
        return false;
    }
};
