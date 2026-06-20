class Solution {
private:
    int sinkIsland(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;
        return 1 + sinkIsland(grid, r - 1, c)
                 + sinkIsland(grid, r + 1, c)
                 + sinkIsland(grid, r, c - 1)
                 + sinkIsland(grid, r, c + 1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int currentArea = sinkIsland(grid, i, j);
                    maxArea = max(maxArea, currentArea);
                }
            }
        }

        return maxArea;
    }
};
