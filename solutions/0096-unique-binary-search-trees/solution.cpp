class Solution {
public:
    int numTrees(int n) {
        long long catalan = 1;
        for (int i =0; i <n; i++) {
            catalan = catalan * (2*n-i) /(i+1);
        }
    
        return (int)(catalan /(n+1));
    }
};

