class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        vector<int> st;
        long long ans=0;

        for(int j=0; j<nums.size(); j++){
            auto it= lower_bound(st.begin(), st.end(), nums[j]);
            ans +=it- st.begin();
            while(!st.empty() &&st.back() >nums[j]){
                st.pop_back();
            }
            st.push_back(nums[j]);
        }
        return ans;
    }
};
