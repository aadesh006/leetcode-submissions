class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int,int>hashMap;
        for (char c : text) {
            hashMap[c]++;
        }
        int b = hashMap['b'];
        int a = hashMap['a'];
        int l = hashMap['l'] / 2;
        int o = hashMap['o'] / 2;
        int n = hashMap['n'];
        
        return min({b, a, l, o, n});
    }
};
