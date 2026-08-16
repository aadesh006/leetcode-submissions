class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.length();
        int m=station.length();

        vector<int>right(n);
        int j=m-1;
        for(int i=n-1; i>=0; i--){
            while(i>=0 && station[j]!=skill[i]) j--;
            right[i]=j;
            j--;
        }
        int maxGap=0;
        j=0;
        int prevLeft=0;
        for(int i=0; i<n;i++){
            while(j<m && station[j]!= skill[i]) j++;
            if(i>0) maxGap=max(maxGap, right[i]-prevLeft);
            prevLeft=j;
            j++;
        }
        return maxGap;
    }
};
