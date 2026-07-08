class Solution {
private:
    void dfs(vector<vector<int>>& grid, int r, int c, int minutes, vector<vector<int>>&timeGrid){

        if(grid.empty()) return;
        int rows = grid.size();
        int cols = grid[0].size();

        if(r<0||c<0||r>=rows||c>=cols||grid[r][c] == 0) return;

        if(minutes >= timeGrid[r][c]) return;
        timeGrid[r][c] = minutes;
;
        dfs(grid, r+1, c, minutes+1, timeGrid);
        dfs(grid, r-1, c, minutes+1, timeGrid);
        dfs(grid, r, c-1, minutes+1, timeGrid);
        dfs(grid, r, c+1, minutes+1, timeGrid);
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> timeGrid(rows, vector<int>(cols, 1e9));
        int ans=0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 2){
                    dfs(grid, i, j, 0, timeGrid);
                }
            }
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){;
                    if(timeGrid[i][j] == 1e9) return -1;
                    ans = max(ans, timeGrid[i][j]);
                }
            }
        }
        return ans;
    }
};
