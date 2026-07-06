class Solution {
private:
    int getNext(int n) {
        int totalSum = 0;
        string s = to_string(n);
        
        for (char ch : s) {
            int digit = ch - '0';
            totalSum += digit * digit;
        }
        return totalSum;
    }

public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getNext(n);
        }
        
        return n == 1;
    }
};
