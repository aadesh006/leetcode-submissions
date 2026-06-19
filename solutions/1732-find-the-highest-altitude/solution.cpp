class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitudes;
        altitudes.push_back(0);
        
        for(int i = 0; i < gain.size(); i++){
            altitudes.push_back(altitudes[i] + gain[i]);
        }
        
        auto max_alt = max_element(altitudes.begin(), altitudes.end());

        return *max_alt;
    }
};

