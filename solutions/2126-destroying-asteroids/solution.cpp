class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        sort(asteroids.begin(), asteroids.end());
        long long planetMass = mass;
        
        for (int i =0; i <n; i++) {
            if (asteroids[i] > planetMass) return false;
            planetMass += asteroids[i];
        }
        return true;
    }
};

