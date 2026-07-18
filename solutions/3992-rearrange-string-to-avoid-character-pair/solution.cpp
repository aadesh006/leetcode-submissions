class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string yStr, mid, xStr;

        for(char c : s){
            if(c == y) yStr += c;
            else if(c==x) xStr += c;
            else mid += c;
        }
        return yStr+mid+xStr;
    }
};
