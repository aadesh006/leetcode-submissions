class Solution {
private:
    void dfs(vector<vector<int>>& grid, int r, int c, int visitedCount, int& walkCells, int& totalPath){
        int rows= grid.size();
        int cols= grid[0].size();
        if(r<0 || c<0|| c>=cols ||r>=rows || grid[r][c] ==-1) return;

        if(grid[r][c] ==2){
            if(visitedCount == walkCells) totalPath++;
            return;
        }

        int temp=grid[r][c];
        grid[r][c] =-1;
        dfs(grid, r+1, c, visitedCount+1, walkCells, totalPath);
        dfs(grid, r, c+1, visitedCount+1, walkCells, totalPath);
        dfs(grid, r, c-1, visitedCount+1, walkCells, totalPath);
        dfs(grid, r-1, c, visitedCount+1, walkCells, totalPath);
        grid[r][c] =temp;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int walkCells=0;
        int totalPath=0;
        int rows=grid.size();
        int cols=grid[0].size();
        int startX=0;
        int startY=0;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] != -1){
                    walkCells++;
                }
                if(grid[r][c]==1){
                    startX=r;
                    startY=c;
                }
            }
        }
        dfs(grid, startX, startY, 1, walkCells, totalPath);
        return totalPath;
    }
};
