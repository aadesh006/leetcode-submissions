class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {

        vector<vector<int>> ans;

        int left =0, right=0;
        int n=series1.size();
        int m=series2.size();
        while(left<n || right<m){
            int t;
            if(left ==n) t=series2[right][0];
            else if(right ==m) t =series1[left][0];
            else t =min(series1[left][0], series2[right][0]);
            int val1=0;
            int val2=0;

            if(left<n){
                val1 = series1[left][1];
                if(series1[left][0] ==t)left++;
            }
            if(right<m){
                val2= series2[right][1];
                if(series2[right][0]==t)right++;
            }
            ans.push_back({t, val1+val2});
        }
        return ans;
    }
};
