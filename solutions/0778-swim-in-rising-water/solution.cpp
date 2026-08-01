class Solution {
private:
    int dirs[4][2] ={{-1,0}, {1,0}, {0,-1}, {0,1}};
    int n;
    bool dfs(int r, int c, int maxTime, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(r == n-1 && c ==n-1) return true;
        visited[r][c] = true;

        for(auto& dir : dirs){
            int nr = r+dir[0];
            int nc = c+dir[1];

            if(nr>=0 &&nr<n &&nc>=0 &&nc<n && visited[nr][nc]!=true){
                if(grid[nr][nc] <= maxTime){
                    if(dfs(nr, nc, maxTime, grid, visited)) return true;
                }
            }
        }
        return false;
    } 
public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int low = grid[0][0];
        int high = n*n-1;
        int ans =high;

        while(low <= high){
            int mid = low +(high-low)/2;
            vector<vector<bool>>visited(n, vector<bool>(n, false));

            if(grid[0][0] <=mid && dfs(0, 0, mid, grid, visited)){
                ans = mid;
                high =mid-1;
            } else{
                low = mid+1;
            }
        }
        return ans;
    }
};
