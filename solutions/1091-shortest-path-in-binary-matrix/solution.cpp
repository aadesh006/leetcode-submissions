class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n == 1) return 1;

        grid[0][0] = 1;
        queue<pair<int, int>>q;
        q.push({0,0});

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 1, 0, -1, 1, 0, -1, 1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            int currLen = grid[r][c];

            for(int i=0; i<8; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0&&nc>=0&&nr<n&&nc<n&&grid[nr][nc] == 0){
                    if(nr == n-1 && nc == n-1) return currLen+1;
                    grid[nr][nc] = currLen +1;
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};
