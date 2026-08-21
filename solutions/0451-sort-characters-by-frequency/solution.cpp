class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int, int>hashMap;
        for(int i=0; i<s.size(); i++){
            hashMap[s[i]]++;
        }
        vector<pair<char, int>> v(hashMap.begin(), hashMap.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string result="";
        for(auto c : v){
            result.append(c.second, c.first);
        }
        return result;
    }
};
