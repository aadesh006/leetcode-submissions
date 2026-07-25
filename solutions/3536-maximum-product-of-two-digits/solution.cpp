class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        int len = s.length();
        int maxDigit1 = s[len - 1] - '0';
        int maxDigit2 = s[len - 2] - '0';
        
        return maxDigit1*maxDigit2;
    }
};

