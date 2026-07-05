class Solution {
private:
    int digitRange(int n){
        int maxElemet=0, minElemet=9;
        while(n>0){
            int d =n%10;
            maxElemet =max(maxElemet,d);
            minElemet =min(minElemet,d);
            n/=10;
        }
        return maxElemet-minElemet;
    }
public:
    int maxDigitRange(vector<int>& nums) {
        int maxRange=0;
        for(int n : nums) {
            maxRange=max(maxRange, digitRange(n));
        }
        long long sum =0;
        for(int n : nums){
            if(digitRange(n) ==maxRange) sum+=n;
        }
        return sum;
    }
};
