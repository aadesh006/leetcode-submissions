class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>hashMap;

        for(int i =0; i<nums.size(); i++){
            int current = nums[i];
            int needed = target - current;

            if(hashMap.count(needed)){
                return{hashMap[needed],i};
            }

            hashMap[nums[i]] = i;
        }

        return {};
    }
};
