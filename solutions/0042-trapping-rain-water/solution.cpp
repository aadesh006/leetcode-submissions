class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>leftMax(n);
        vector<int>rightMax(n);

        leftMax[0] = height[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[n-1] = height[n-1];
        for(int i= n-2; i>=0;i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        vector<int>minCap(n);
        for(int i=0; i<n;i++){
            minCap[i] = min(leftMax[i], rightMax[i]);
        }

        int totalCap =0;
        for(int i =0; i<n; i++){
            totalCap+= minCap[i] - height[i];
        }
        return totalCap;
    }
};
