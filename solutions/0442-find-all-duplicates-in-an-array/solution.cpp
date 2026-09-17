class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int>hashMap;
        vector<int>duplicates;
        for(int i : nums){
            hashMap[i]++;
        }
        for(auto const& [num, count] :hashMap) {
            if(count==2) duplicates.push_back(num);
        }
        
        return duplicates;
    }
};
