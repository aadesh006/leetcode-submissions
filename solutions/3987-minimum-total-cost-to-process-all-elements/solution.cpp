class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9+7;
        const long long INV2 = 500000004;
        long long R = k;
        long long m =0;
        long long K =k;

        for(int x : nums){
            long long num =x;
            if(R<num){
                long long needed = num-R;
                long long t = (needed+K-1)/K;
                m +=t;
                R +=t*K;
            }
            R -= num;
        }
        long long mm = m%MOD;
        long long mp = (m+1)%MOD;
        long long ans = ((mm*mp)%MOD)*INV2%MOD;
        return (int)ans;
    }
};
