class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int seen [128] = {0};
        int left = 0;
        int maxlength =0;

        for(int right =0; right<s.length(); right++){
            char currentChar = s[right];
            left = max(left, seen[currentChar]);

            maxlength = max(maxlength, right-left+1);

            seen[currentChar] = right+1;
        }
        return maxlength;
    }
};
