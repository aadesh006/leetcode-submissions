class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& v : matrix) {
            int left =0;
            int right =v.size()-1;

            while (left<=right) {
                int mid = left +(right-left)/2;
                if (v[mid]==target) return true;
                else if (v[mid] <target) left =mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
};
