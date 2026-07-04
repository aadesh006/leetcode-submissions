class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjList(n + 1);

        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        int ans = INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &[neighbor, wt] : adjList[node]){
                ans = min(ans, wt);
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return ans;
    }
};
