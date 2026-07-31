class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>hashMap;
        vector<int> result;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            hashMap[nums[i]]++;
        }
        for(auto& num : hashMap){
            if(num.second > n/3) result.push_back(num.first);
        }
        return result;

    }
};
