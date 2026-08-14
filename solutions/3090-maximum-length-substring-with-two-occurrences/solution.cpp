class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> count(26, 0);
        int l = 0;
        int max_len = 0;
        
        for (int r = 0; r < s.length(); ++r) {
            count[s[r] - 'a']++;
            while (count[s[r] - 'a'] > 2) {
                count[s[l] - 'a']--;
                l++;
            }
            max_len =max(max_len, r-l+1);
        }
        return max_len;
    }
};
