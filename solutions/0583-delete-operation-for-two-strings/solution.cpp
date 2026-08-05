class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] =i;
        for(int i=0; i<=m; i++) dp[0][i] =i;

        for(int r=1; r<=n; r++){
            for(int c=1; c<=m; c++){

                if(word1[r-1] == word2[c-1]) dp[r][c] = dp[r-1][c-1];

                else dp[r][c] = 1+ min(dp[r-1][c], dp[r][c-1]);
            }
        }
        return dp[n][m];
    }
};
