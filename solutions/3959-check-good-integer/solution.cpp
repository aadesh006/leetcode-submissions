class Solution {
public:
    bool checkGoodInteger(int n) {
        string result = to_string((int)n);
        int digitSum = 0;

        for(char c : result){
            int myInt = c - '0';
            digitSum += myInt;
        }

        int squareSum = 0;
        for(char c : result){
            int myInt = c - '0';
            myInt *= myInt;
            squareSum += myInt;
        }

        if((squareSum - digitSum) >= 50){
            return true;
        }

        return false;
    }
};
