class Solution {
    int maxCycle;
private:
    void dfs(int node, vector<int>& edges, vector<int>& state, vector<int>& dist, int currentDist){

        state[node] = 1;
        dist[node] = currentDist;

        int neighbor = edges[node];

        if(neighbor != -1){
            if(state[neighbor] == 0){
                dfs(neighbor, edges, state, dist, currentDist+1);
            } else if(state[neighbor] == 1){
                int cycleLength = currentDist - dist[neighbor] +1;
                maxCycle = max(cycleLength, maxCycle);
            }
        }
        state[node] = 2;
    }
public:
    int longestCycle(vector<int>& edges) {
        if(edges.empty()) return 0;
        int n = edges.size();
        maxCycle =-1;
        vector<int> state(n, 0);
        vector<int> dist(n, 0);

        for(int i=0; i<n; i++){
            if(state[i] == 0){
                dfs(i, edges, state, dist, 1);
            }
        }

        return maxCycle;
    }
};
