class Solution {
private:
    long long MOD = 1e9 + 7;
    vector<long long> fact;
    vector<long long> invFact;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

    void precompute(int n) {
        fact.resize(n + 1, 1);
        invFact.resize(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[n] = modInverse(fact[n]);
        for (int i = n - 1; i >= 2; --i) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    long long dfs(vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        int root = nums[0];
        vector<int> left, right;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long combinations = nCr(left.size() + right.size(), left.size());
        long long left_ways = dfs(left);
        long long right_ways = dfs(right);

        return (((combinations * left_ways) % MOD) * right_ways) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        precompute(n);
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};

