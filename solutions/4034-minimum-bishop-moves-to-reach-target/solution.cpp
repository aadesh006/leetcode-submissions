class Solution {
private:
    bool isSameColor(int r1, int c1, int r2, int c2){
        return (r1+r2)%2 == (c1+c2)%2;
    }
    bool isSameDiagonal(int r1, int c1, int r2, int c2){
        return abs(r1-r2)==abs(c1-c2);
    }
    
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr=source[0], sc=source[1];
        int tr=target[0], tc=target[1];
        if(sr==tr&&sc==tc) return 0;
        if(!isSameColor(sr, sc, tr, tc)) return -1;
        if(isSameDiagonal(sr,sc,tr,tc)) return 1;
        return 2;
    }
};
