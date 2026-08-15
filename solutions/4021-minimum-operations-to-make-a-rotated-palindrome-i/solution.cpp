class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        string dStr=s+s;
        int minOps=INT_MAX;
        
        for(int k=0; k<n; k++){
            int currentOps=k;
            int left=k;
            int right=k+n-1;
            while(left<right){
                int diff=abs(dStr[left]-dStr[right]);
                currentOps+=min(diff,26-diff);
                left++;
                right--;
            }
            minOps=min(minOps,currentOps);
        }
        return minOps;
    }
};
