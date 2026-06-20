class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>result (m,string(n, '#'));

        int i =0, j=0;
        result[0][0] = '.';

        while(j+1<n) result[i][++j] = '.';
        while(i+1<m) result[++i][j] = '.';

        return result;
    }
};
