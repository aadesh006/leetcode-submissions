class Solution {
private:
    long long modPow(long long a, long long b){
        long long MOD=1e9+7;
        long long res=1;
        a%=MOD;
        while(b>0){
            if(b%2==1) res=(res*a)%MOD;
            a=(a*a)%MOD;
            b/=2;
        }
        return res;
    }
public:
    int sumDecoded(vector<long long>& nums) {
        long long totalSum=0;
        long long MOD=1e9+7;
        for(long long num :nums){
            int width =num%10;
            long long d=num/10;
            string s=to_string(d);
            long long x=stoll(s.substr(0, width));
            long long y=stoll(s.substr(width));
            totalSum=(totalSum+modPow(x, y))%MOD;
        }
        return totalSum;
    }
};
