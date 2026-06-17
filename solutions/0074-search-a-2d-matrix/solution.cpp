class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const vector<int>& v : matrix) {    
            if (v.empty() || target < v[0] || target > v.back()) {
                continue; 
            }

            int left = 0;
            int right = v.size() - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (v[mid] == target) {
                    return true;
                } else if (v[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

