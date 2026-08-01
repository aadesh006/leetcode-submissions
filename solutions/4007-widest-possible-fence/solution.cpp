class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, long long>count;
        for(int x:planks) count[x]++;
        vector<int>vals;
        for(auto& [v,c] :count)vals.push_back(v);
        int D= vals.size();
        
        unordered_map<long long, long long>s;
        for(int v:vals) s[v]+=count[v];
        for(int v:vals){
            if(count[v]>=2) s[2LL*v]+=count[v]/2;
        }
        for(int i=0; i<D; i++)
            for(int j=i+1; j<D; j++)
                s[(long long)vals[i]+vals[j]] +=
                    min(count[vals[i]],count[vals[j]]);
        
        long long ans=0;
        for(auto& [h,c] : s) ans=max(ans, c);
        return (int)ans;
    }
};
