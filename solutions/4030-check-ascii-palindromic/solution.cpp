class Solution {
public:
    bool isPalindromic(string s) {
        string ans;
        for(int i=7; i>=0; i--){
            for(char c : s){
                ans+=((c>>i)&1)+'0';
            }
        }
        string r=ans;
        reverse(r.begin(), r.end());
        return r==ans;
    }
};
