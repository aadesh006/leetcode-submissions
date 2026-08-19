class Solution {
    const long long MOD = 1e9 + 7;
private:
    long long modPow(long long a, long long n) {
        long long result = 1;
        a %= MOD;
        while (n > 0) {
            if (n & 1) result = (result * a) % MOD;
            a = (a*a)%MOD;
            n >>=1;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;
        
        long long ans =(modPow(5, evenCount) *modPow(4, oddCount)) %MOD;
        return ans;
    }
};
