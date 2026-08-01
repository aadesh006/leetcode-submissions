class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt1 =0, cnt2 =0;
        int ans=0;
        for(char c: s){
            if(c =='0')cnt1++;
            else cnt2++;
            if(abs(cnt1-cnt2)<=1) ans++;
        }
        return ans;
    }
};
