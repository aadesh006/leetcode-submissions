class Solution {
public:
    bool checkDivisibility(int n) {
        string s= to_string(n);
        int digitSum=0;
        int digitProduct=1;

        for(int i=0; i<s.length(); i++) digitSum += std::stoi(string(1,s[i]));
        for(int i=0; i<s.length(); i++) digitProduct *= std::stoi(string(1,s[i]));
        int totalSum=digitSum+digitProduct;

        if(totalSum ==0) return false;
        if(n%totalSum !=0) return false;
        return true;
    }
};
