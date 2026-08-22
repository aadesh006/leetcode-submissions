class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0; i<n; i++) totalSum+=nums[i];
        int subset=(target+totalSum)/2;

        if(target>totalSum || subset<0|| (target + totalSum)%2 != 0) return 0;

        vector<vector<int>>dp(n+1, vector<int>(subset+1, 0));
        dp[0][0]=1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=subset; j++){
                if(j>=nums[i-1]){
                    dp[i][j] = dp[i-1][j]+dp[i-1][j -nums[i-1]];
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][subset];
    }
};
