class Solution {
public:
    int maxDistance(string moves) {
        int U = 0, D = 0, L = 0;
        int R = 0, Q = 0;
        for(char ch : moves){
            if(ch == 'U') U++;
            else if (ch == 'D') D++;
            else if (ch == 'L') L++;
            else if (ch == 'R') R++;
            else Q++;
        }

        int ans = abs(R-L) +abs(U-D) +Q;
        return ans;
    }
};
