class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

        for(int i =0; i<=m; i++) dp[i][0] = i;
        for(int j=0; j<=n; j++) dp[0][j] = j;

        for(int r=1; r<=m; r++){
            for(int c=1; c<=n; c++){
                if(word1[r-1] == word2[c-1]){ 
                    dp[r][c] = dp[r-1][c-1];
                }else{
                    dp[r][c] = 1+ min({dp[r-1][c],
                                       dp[r-1][c-1],
                                       dp[r][c-1]});
                }
            }
        }
        return dp[m][n];
    }
};
