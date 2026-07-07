class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        string s = to_string(n);
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        long long num = stoll(s);
        long long sum =0;

        for(char c : s){
            sum += c - '0';
        }

        return sum*num;
    }
};
