class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        bool isNegative = (x<0);
        string s = to_string(abs(x));
        std::reverse(s.begin(), s.end());
        long long reversedVal = stoll(s);

        if(isNegative) reversedVal = -reversedVal;
        if(reversedVal < INT_MIN || reversedVal > INT_MAX) return 0;

        return static_cast<int>(reversedVal);
    }
};
