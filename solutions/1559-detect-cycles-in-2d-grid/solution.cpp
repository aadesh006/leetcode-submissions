class Solution {
private:
    bool dfs(vector<vector<char>>& grid, int r, int c, int pr, int pc, vector<vector<bool>>& vis) {

        int rows = grid.size();
        int cols = grid[0].size();
        vis[r][c] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)continue;
            if (grid[nr][nc] != grid[r][c]) continue;


            if (nr == pr && nc == pc) continue;
            if (vis[nr][nc]) return true;
            if (dfs(grid, nr, nc, r, c, vis)) return true;
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (!vis[r][c]) {
                    if (dfs(grid, r, c, -1, -1, vis)) return true;
                }
            }
        }
        return false;
    }
};

