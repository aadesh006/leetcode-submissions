class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int result = 0;
        for(const string& s: patterns){
            if(word.contains(s)) result++;
        }
        return result;
    }
};
