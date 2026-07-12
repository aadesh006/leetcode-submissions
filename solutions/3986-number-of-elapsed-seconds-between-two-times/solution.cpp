class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        auto sec = [](string &t){
            int h = stoi(t.substr(0,2));
            int m = stoi(t.substr(3,2));
            int s = stoi(t.substr(6,2));
            return h*3600 +m*60+s;
        };
        return sec(endTime) - sec(startTime);
    }
};
