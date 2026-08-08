class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n= matrix.size();
        unordered_set<char> rows[n];
        unordered_set<char> cols[n];

        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                int val =matrix[r][c];
                if(rows[r].count(val) || cols[c].count(val)) return false;
                rows[r].insert(val);
                cols[c].insert(val);
            }
        }
        return true;
    }
};
