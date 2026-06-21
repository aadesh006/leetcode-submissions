class Solution {
private:
    int helperFirstDigit(long long x){
        while( x >=10){
            x = x/10;
        }
        return x;
    }
public:
    long long countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        long long result = 0;

        for(int i=0; i<n; i++){
            long long sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];

                if(sum %10 != x ) continue;
                if(helperFirstDigit(sum) == x){
                    result++;
                }
            }
        }

        return result;
    }
};
