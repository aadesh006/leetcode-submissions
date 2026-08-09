class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n=mat[0].size();

        vector<vector<int>> pre(m+1, vector<int>(n+1, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                pre[i+1][j+1] =mat[i][j] +pre[i][j+1]+pre[i+1][j]-pre[i][j];
            }
        }
        auto sum =[&](int r1, int c1, int r2, int c2){
            return pre[r2+1][c2+1] -pre[r1][c2+1] -pre[r2+1][c1]+pre[r1][c1];
        };

        auto feasible=[&](int k){
            int minR = INT_MAX;
            int maxR = INT_MIN;
            int minC=INT_MAX;
            int maxC = INT_MIN;
            int cnt=0;
            for(int r=0; r+k<=m; r++){
                for(int c=0; c+k<=n; c++){
                    if(sum(r, c, r+k-1, c+k-1) == k*k){
                        cnt++;
                        minR = min(minR, r);
                        maxR = max(maxR, r);
                        minC= min(minC, c);
                        maxC  =max(maxC, c);
                    }
                }
            }
            return cnt>=2&&(maxR -minR>=k || maxC -minC>=k);
        };

        int low=1, high =min(m,n);
        int best =0;
        while(low<=high){
            int mid =(low+high)/2;
            if(feasible(mid)){
                best =mid;
                low=mid+1;
            } else{
                high =mid-1;
            }
        }
        return best*best;
    }
};
