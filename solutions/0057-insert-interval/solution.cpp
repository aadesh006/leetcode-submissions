class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<vector<int>>mergedIntervals;
        for(auto& interval : intervals){
            if(mergedIntervals.empty() || interval[0] > mergedIntervals.back()[1]){
                mergedIntervals.push_back(interval);
            } else{
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[1]);
            }
        }
        return mergedIntervals;
    }
};
