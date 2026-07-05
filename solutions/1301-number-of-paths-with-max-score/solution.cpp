class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        dp[n - 1][n - 1] = {0, 1};
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'X' || dp[i][j].first == -1) {
                    continue;
                }
                
                int curr_score = dp[i][j].first;
                int curr_paths = dp[i][j].second;
                int dirs[3][2] = {{i - 1, j}, {i, j - 1}, {i - 1, j - 1}};
                
                for (auto& dir : dirs) {
                    int ni = dir[0];
                    int nj = dir[1];
                    
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] != 'X') {
                        int cell_value = (board[ni][nj] == 'E') ? 0 : (board[ni][nj] - '0');
                        int next_score = curr_score + cell_value;
                        
                        if (next_score > dp[ni][nj].first) {
                            dp[ni][nj].first = next_score;
                            dp[ni][nj].second = curr_paths;
                        } else if (next_score == dp[ni][nj].first) {
                            dp[ni][nj].second = (dp[ni][nj].second + curr_paths) % MOD;
                        }
                    }
                }
            }
        }
        
        if (dp[0][0].first == -1) return {0, 0};
        return {dp[0][0].first, dp[0][0].second};
    }
};

