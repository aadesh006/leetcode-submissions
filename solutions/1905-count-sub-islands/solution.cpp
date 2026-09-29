class Solution {
    int rows, cols;
private:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c){
        if(r<0 || c<0|| r>=rows|| c>=cols|| grid2[r][c]== 0) return true;
        grid2[r][c]=0;

        bool isSubIsland = (grid1[r][c] ==1);
        isSubIsland &=dfs(grid1, grid2, r+1, c);
        isSubIsland &=dfs(grid1, grid2, r-1, c);
        isSubIsland &=dfs(grid1, grid2, r, c-1);
        isSubIsland &=dfs(grid1, grid2, r, c+1);
        return isSubIsland;

    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        rows = grid2.size();
        cols = grid2[0].size();

        int IslandCount = 0;
        for (int r=0; r<rows; r++) {
            for (int c=0; c<cols; c++) {
                if (grid2[r][c] ==1) {
                    if (dfs(grid1, grid2, r, c)) {
                        IslandCount++;
                    }
                }
            }
        }

        return IslandCount;
    }
};
