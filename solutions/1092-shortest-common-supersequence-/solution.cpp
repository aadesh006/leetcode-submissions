class Solution {
private:
    string LCS(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n+1, vector<int> (m+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){

                if(text1[i-1] == text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string lcs_str="";
        int i=n, j=m;
        while(i>0 && j>0){
            if(text1[i-1] == text2[j-1]){
                lcs_str.push_back(text1[i-1]);
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            } else{
                j--;
            }
        }
        reverse(lcs_str.begin(), lcs_str.end());
        return lcs_str;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs_str = LCS(str1, str2);
        string result="";
        int i=0, j=0;

        for(char c : lcs_str){
            while(str1[i] != c){
                result.push_back(str1[i]);
                i++;
            }
            while(str2[j] != c){
                result.push_back(str2[j]);
                j++;
            } 
            result+=c;
            i++; j++;
        }

        result += str1.substr(i) + str2.substr(j);
        return result;
    }
};
