class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const long long MOD = 1e9+7;
        long long oneSeen = 0;
        long long twoSeen = 0;
        long long ans =0;

        for(int x : nums){
            int l;
            if(x<a) l = 0;
            else if (x<=b) l =1;
            else l =2;

            if(l==0) ans = (ans +oneSeen+twoSeen)%MOD;
            else if (l ==1){ 
                ans = (ans+twoSeen)%MOD;
                oneSeen++;
            } else{
                twoSeen++;
            }
        }
        return (int)ans;
    }
};
