class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>hashMap;
        int n=nums.size();
        for(int i=0; i<n; i++){
            hashMap[nums[i]]++;

            if(hashMap[nums[i]] > n/2) return nums[i];
        }
        return -1;
    }
};
