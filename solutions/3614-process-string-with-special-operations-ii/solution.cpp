class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> lengthArr(n, 0);
        
        if (s[0] == '*' || s[0] == '#' || s[0] == '%') {
            lengthArr[0] = 0;
        } else {
            lengthArr[0] = 1;
        }
        
        for (int i = 1; i < n; i++) {
            if (s[i] == '*') {
                lengthArr[i] = max(0LL, lengthArr[i - 1] - 1);
            } else if (s[i] == '#') {
                lengthArr[i] = lengthArr[i - 1] * 2;
            } else if (s[i] == '%') {
                lengthArr[i] = lengthArr[i - 1];
            } else {
                lengthArr[i] = lengthArr[i - 1] + 1;
            }
        }
        
        if (k < 0 || k >= lengthArr[n - 1]) {
            return '.';
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '#') {
                if (i > 0 && lengthArr[i - 1] > 0) {
                    k = k % lengthArr[i - 1];
                }
            } 
            else if (s[i] == '%') {
                if (i > 0 && lengthArr[i - 1] > 0) {
                    k = lengthArr[i - 1] - 1 - k;
                }
            } 
            else if (s[i] != '*') {
                long long current_letter_index = (i > 0) ? lengthArr[i - 1] : 0;
                
                if (k == current_letter_index) {
                    return s[i];
                }
            }
        }
        
        return '.';
    }
};

