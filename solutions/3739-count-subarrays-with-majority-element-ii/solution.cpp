class Solution {
public:
    long long countMajoritySubarrays(std::vector<int>& nums, int target) {
        long long ans = 0;
        int current_sum = 0;
        std::unordered_map<int, int> freq;
        freq[0] = 1;
        int smaller_counts = 0; 
        
        for (int x : nums) {
            if (x == target) {
                smaller_counts += freq[current_sum];
                current_sum++;
            } else {
                current_sum--;
                smaller_counts -= freq[current_sum];
            }
            freq[current_sum]++;
            
            ans += smaller_counts;
        }
        
        return ans;
    }
};

