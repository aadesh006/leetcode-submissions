class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime){
        int maxLight=0;
        for(int l: lights){
            if(l>maxLight) maxLight=l;
        }

        int minPen=0;
        for(int t: arrivalTime){
            int r=t%period;
            if(r>=maxLight){
                int penalty=period-r;
                if(penalty>minPen) minPen=penalty;
            }
        }
        return minPen;
    }
};
