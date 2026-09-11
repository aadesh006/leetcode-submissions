class Solution {
private:
int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int r, int c, int preVal){
    int rows=matrix.size();
    int cols=matrix[0].size();
    if (r<0 || r>=rows || c<0 || c>=cols || matrix[r][c]<=preVal) return 0;
    if (memo[r][c] !=0) return memo[r][c];

    int down=dfs(matrix, memo, r+1, c, matrix[r][c]);
    int up =dfs(matrix, memo, r-1, c, matrix[r][c]);
    int right=dfs(matrix, memo, r, c+1, matrix[r][c]);
    int left =dfs(matrix, memo, r, c-1, matrix[r][c]);

    return memo[r][c]= 1 + max({down, up, right, left});
}

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows=matrix.size();
        int cols=matrix[0].size();
        int result=0;

        vector<vector<int>> memo(rows, vector<int>(cols, 0));

        for (int r =0; r<rows; r++) {
            for (int c =0; c<cols; c++) {
                result = max(result, dfs(matrix, memo, r, c, INT_MIN));
            }
        }

        return result;
    }
};
