class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int>rotatedArr(n);

        for(int k=0; k<n; k++){
            for(int i=0; i<n ;i++){
                rotatedArr[i] = nums[(i+k)%n];
            }
            if(is_sorted(rotatedArr.begin(), rotatedArr.end())) return true;
        }
        return false;
    }
};
