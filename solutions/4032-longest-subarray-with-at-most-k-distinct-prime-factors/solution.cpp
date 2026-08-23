class Solution {
private:
    vector<int>factors(int x){
        vector<int> f;
        for(int i=2; i*i<=x; i++){
            if(x%i ==0){
                f.push_back(i);
                while(x%i ==0) x/=i;
            }
        }
        if(x>1)f.push_back(x);;
        return f;
    }
public:
    int longestSubarray(vector<int>& nums, int k) {
        int l=0, ans=0, dist=0;
        unordered_map<int, int>cnt;
        int n=nums.size();
        vector<vector<int>>f(n);

        for(int i=0; i<n; i++) f[i] =factors(nums[i]);
        for(int r=0; r<n; r++){
            for(int p: f[r]){
                if(++cnt[p] ==1) dist++;
            }

            while(dist>k){
                for(int p:f[l]){
                    if(--cnt[p] ==0) dist--;
                }
                l++;
            }
            ans =max(ans, r-l+1);
        }
        return ans;
    }
};
