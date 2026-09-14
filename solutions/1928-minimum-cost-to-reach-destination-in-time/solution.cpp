class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n =passingFees.size();
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> minTime(n, INT_MAX);
        pq.push({passingFees[0], 0, 0});
        minTime[0]=0;
        
        while (!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            
            int currCost = curr[0];
            int currTime = curr[1];
            int u = curr[2];
            
            if (u== n-1) return currCost;
            
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int travelTime = neighbor.second;
                
                int nextTime= currTime+travelTime;
                int nextCost =currCost+passingFees[v];
                
                if (nextTime<= maxTime && nextTime < minTime[v]) {
                    minTime[v] = nextTime;
                    pq.push({nextCost, nextTime, v});
                }
            }
        }
        return -1;
    }
};

