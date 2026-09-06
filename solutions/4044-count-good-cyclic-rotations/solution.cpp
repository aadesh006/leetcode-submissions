class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        int k=n/2;

        long long sum1=0;
        long long sum2=0;
        for(int i=0; i<k; i++){
            sum1+=nums[i];
            sum2+=nums[i+k];
        }
        int goodCount=0;
        for(int i=0; i<n; i++){
            if(sum1>sum2) goodCount++;
            long long leaveSum1=nums[i];
            long long enterSum1=nums[(i+k)%n];
            sum1= sum1- leaveSum1+ enterSum1;
            sum2= sum2 - enterSum1+ leaveSum1;
        }
        return goodCount;
    }
};
