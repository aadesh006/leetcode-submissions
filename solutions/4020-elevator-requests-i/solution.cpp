class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int time=0;
        int currentFloor=0;
        int siz=requests.size();
        for(int i=0; i<siz; i++){
            time+=abs(requests[i]-currentFloor);
            currentFloor=requests[i];
        }
        return time;
    }
};
