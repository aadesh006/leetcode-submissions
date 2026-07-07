class Solution {
public:
    bool isGoodArray(std::vector<int>& nums) {
        int gcd = nums[0];
        
        for (int num : nums) {
            gcd = std::gcd(gcd, num);
            if (gcd == 1) return true;
        }
        
        return gcd == 1;
    }
};
