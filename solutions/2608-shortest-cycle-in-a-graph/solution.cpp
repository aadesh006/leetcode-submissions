class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int minCycle = 1e9;
        for(int i=0; i<n ;i++){
            vector<int> dist(n, 1e9);
            dist[i] = 0;

            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(int v : adjList[u]){
                    if(dist[v] == 1e9){
                        dist[v] = dist[u]+1;
                        q.push(v);
                    } else if(dist[v]>=dist[u]){
                        minCycle = min(minCycle, dist[u] + dist[v]+1);
                    }
                }
            }
        }

        if(minCycle == 1e9) return -1;
        return minCycle;
    }
};
