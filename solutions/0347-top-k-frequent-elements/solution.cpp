class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int>hashMap;

        for(int num : nums){
            hashMap[num]++;
        }

        vector<pair<int,int>>freqVec;
        for(auto const& [key, value] : hashMap){
            freqVec.push_back({value,key});
        }

        sort(freqVec.rbegin(), freqVec.rend());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(freqVec[i].second);
        }

        return ans;
    }
};
