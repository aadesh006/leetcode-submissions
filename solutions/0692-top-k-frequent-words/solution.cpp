class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>hashMap;
        for(string s: words){
            hashMap[s]++;
        }
        auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
        
        for (auto& it : hashMap) {
            pq.push({it.second, it.first});
            if (pq.size() > k) pq.pop();
        }
        vector<string> result(k);
        for (int i= k-1; i>=0; i--) {
            result[i] = pq.top().second;
            pq.pop();
        }
        
        return result;
    }
};
