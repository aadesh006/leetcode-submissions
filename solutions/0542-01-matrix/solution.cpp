class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m =mat[0].size();

        vector<vector<int>>result(n, vector<int>(m, -1));
        queue<pair<int, int>>q;
        int dr[] ={-1,1, 0,0};
        int dc[]={0, 0, -1,1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] ==0){
                    result[i][j] =0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && result[nr][nc] ==-1){
                    result[nr][nc] = result[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return result;
    }
};
