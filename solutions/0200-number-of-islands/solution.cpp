class Solution {
private:
    void sinkIsland(vector<vector<char>>& grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();

        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0'){
            return;
        }

        grid[r][c] = '0';
        sinkIsland(grid, r-1, c);
        sinkIsland(grid, r+1, c);
        sinkIsland(grid, r, c+1);
        sinkIsland(grid, r, c-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int countIsland = 0;

        if(grid.empty()) return 0;

        for(int i= 0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == '1'){
                    countIsland++;
                    sinkIsland(grid, i, j);
                }
            }
        }

        return countIsland;
    }
};
