class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {

        if(occupiedIntervals.empty()) return{};
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> mergedVec;

        for(auto& it : occupiedIntervals){
            if(mergedVec.empty() || it[0] > mergedVec.back()[1] +1){
                mergedVec.push_back(it);
            } else{
                mergedVec.back()[1] = max(mergedVec.back()[1], it[1]);
            }
        }
        vector<vector<int>>result;
        for(auto& it : mergedVec){
            int l = it[0], r = it[1];
            if(r<freeStart || l>freeEnd){
                result.push_back({l,r});
                continue;
            }

            if(l<freeStart) result.push_back({l, freeStart-1});
            if(r>freeEnd) result.push_back({freeEnd+1, r});
        }

        return result;
    }
};
