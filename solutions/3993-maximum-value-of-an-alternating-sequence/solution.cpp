class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return s;
        long long upMove = n/2;
        long long ans = 1LL*s + upMove * m-(upMove-1);
        return ans;
    }
};
