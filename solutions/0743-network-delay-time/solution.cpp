class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjList(n+1);

        for(auto& time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adjList[u].push_back({v,w});
        }
        vector<int>dist(n+1, INT_MAX);
        dist[k] =0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0,k});
        while(!pq.empty()){
            auto [currentDist, node] = pq.top();
            pq.pop();

            if(currentDist > dist[node]) continue;

            for(auto& neighbor : adjList[node]){
                int nextNode = neighbor.first;
                int weight = neighbor.second;

                if(dist[node] + weight < dist[nextNode]){
                    dist[nextNode] = dist[node] + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        int delay=0;
        for(int i=1; i<=n; i++){
            if (dist[i] == INT_MAX) return -1;
            delay = max(delay, dist[i]);
        }
        return delay;

    }
};
