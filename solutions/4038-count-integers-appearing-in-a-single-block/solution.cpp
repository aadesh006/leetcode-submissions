class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> seen;
        unordered_set<int> bad;
        if(nums.empty()) return 0;
        seen.insert(nums[0]);

        for(int i=1; i<nums.size(); i++){
            if(nums[i]!= nums[i-1]){
                if(seen.count(nums[i])){
                    bad.insert(nums[i]);
                }
                seen.insert(nums[i]);
            }
        }
        return seen.size()-bad.size();
    }
};
