class Solution {
private:
    int getScore(const vector<int>& arr){
        int m=arr.size(), score=0;
        if(m<=1) return 0;
        vector<int> pref=arr;
        vector<int> suff=arr;

        for(int i=1; i<m; i++) pref[i]=gcd(pref[i-1], arr[i]);
        for(int i=m-2; i>=0; i--) suff[i]=gcd(suff[i+1], arr[i]);
        for(int i=0; i<m-1; i++){
            if(pref[i]==suff[i+1]) score++;
        }
        return score;
    }
public:
    int maxValidSplits(vector<int>& nums) {
        int maxScore= getScore(nums);
        for(int i=0; i<nums.size(); i++){
            vector<int> temp=nums;
            temp.erase(temp.begin()+i);
            maxScore=max(maxScore, getScore(temp));
        }
        return maxScore;
    }
};
