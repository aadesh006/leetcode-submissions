class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size(), m=shifts.size();
        vector<long long>pre(n+1,0);
        for(int i=0; i<n; i++)
            pre[i+1]=pre[i]+tasks[i];
        long long total = pre[n];
        vector<int>ans(m);
        long long current=0;
        int p=0;

        for(int j=0; j<m; j++){
            long long nc=current+shifts[j];
            if(nc>=total){
                ans[j]=0;
                current=0;
                p=0;
            }else{
                current=nc;
                while(p<n&&pre[p+1]<=current) p++;
                ans[j]=n-p;
            }
        }
        return ans;
    }
};
