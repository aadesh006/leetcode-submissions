class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());
        int start =lower;
        for(int x:nums){
            if(x<lower) continue;
            if(x>upper) break;
            
            if(x>start) result.push_back({start, x-1});
            start =x+1;
        }
        if(start<=upper) result.push_back({start, upper});
        return result;
    }
};
