class Solution {
private:
    int m, n;
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool dfs(int r, int c, int current_health, vector<vector<int>>& grid, vector<vector<int>>& max_health_at) {
        current_health -= grid[r][c];

        if (current_health <= 0) return false;
        if (r == m - 1 && c == n - 1) return true;
        if (current_health <= max_health_at[r][c]) return false;
        
        max_health_at[r][c] = current_health;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if (dfs(nr, nc, current_health, grid, max_health_at)) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> max_health_at(m, vector<int>(n, 0));
        return dfs(0, 0, health, grid, max_health_at);
    }
};

