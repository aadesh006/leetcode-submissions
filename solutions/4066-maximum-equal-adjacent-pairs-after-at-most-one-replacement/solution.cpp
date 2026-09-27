class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int, int>, int>freq;
        int base=0;

        for(int i=0; i+1<nums.size(); i++){
            if(nums[i]==nums[i+1]) base++;
            else{
                int a=nums[i];
                int b=nums[i+1];
                if(a>b) swap(a,b);
                freq[{a,b}]++;
            }
        }
        int best=0;
        for(auto &p: freq)
            best=max(best, p.second);
        return base+best;
    }
};
