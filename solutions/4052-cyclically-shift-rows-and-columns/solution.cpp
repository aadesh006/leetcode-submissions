class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        for(int i=0;i<n;i++){
            vector<int> r(n);
            for(int j=0; j<n; j++){
                r[(j-rowShift[i]+n)%n] =grid[i][j];
            }
            grid[i]=r;
        }
        for(int j=0; j<n; j++){
            vector<int>c(n);
            for(int i=0; i<n; i++){
                c[(i-colShift[j]+n)%n]=grid[i][j];
            }
            for(int i=0; i<n; i++) grid[i][j]=c[i];
        }
        return grid;
    }
};
