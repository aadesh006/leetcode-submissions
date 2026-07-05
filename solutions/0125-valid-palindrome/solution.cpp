class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";
        for (char c : s) {
            if (isalnum(static_cast<unsigned char>(c))) {
                cleaned += tolower(static_cast<unsigned char>(c));
            }
        }
        int n = cleaned.size();
        
        for(int i=0; i<n; i++){
            if(cleaned[n-i-1] != cleaned[i]) return false;
        }
        
        return true;

    }
};
