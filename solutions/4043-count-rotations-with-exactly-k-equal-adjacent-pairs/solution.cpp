class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.length();
        int circularMatches=0;

        for(int i=0; i<n; i++){
            if(s[i]==s[(i+1)%n]) circularMatches++;
        }
        int validReact=0;

        for(int i=0; i<n; i++){
            int score=circularMatches;
            if(s[i]==s[(i+1)%n]) score--;
            if(score==k) validReact++;
        }
        return validReact;
    }
};
