class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        vector<vector<int>>efforts(rows, vector<int>(cols, INT_MAX));
        efforts[0][0] =0;
        pq.push({0,0,0});

        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!pq.empty()){
            auto current = pq.top();
            pq.pop();

            int currentEfforts = current[0];
            int r = current[1];
            int c = current[2];

            if(r == rows-1 && c== cols-1) return currentEfforts;
            if(currentEfforts > efforts[r][c]) continue;

            for(auto& dir : dirs){
                int nr = r+dir[0];
                int nc = c+dir[1];

                if(nr >= 0 && nr<rows &&nc>=0 &&nc<cols){
                    int nextEffort = max(currentEfforts, abs(heights[r][c] - heights[nr][nc]));

                    if(nextEffort < efforts[nr][nc]){
                        efforts[nr][nc] = nextEffort;
                        pq.push({nextEffort, nr, nc});
                    }
                }
            }
        }
        return 0;
    }
};
