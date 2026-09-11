class Solution {
public:
    long long countCommas(long long n) {
        long ans=0;
        long x=1000;

        while(x<=n){
            ans+=n-x+1;
            x *=1000;
        }
        return ans;
    }
};
