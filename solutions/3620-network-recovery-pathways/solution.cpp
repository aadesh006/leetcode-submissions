class Solution {
private:
    bool isValidPath(int n,const vector<vector<pair<int, int>>>& adj,const vector<int>& topoOrder,const vector<bool>& online,long long k,int targetScore) {

        const long long INF = LLONG_MAX;
        vector<long long> dp(n, INF);
        dp[0] = 0;

        for (int u : topoOrder) {
            if (dp[u] == INF) continue;

            if (u != 0 && u != n - 1 && !online[u])
                continue;

            for (auto &[v, weight] : adj[u]) {

                if (weight < targetScore)
                    continue;

                if (v != n - 1 && !online[v])
                    continue;

                dp[v] = min(dp[v], dp[u] + weight);
            }
        }

        return dp[n - 1] <= k;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);
        vector<int> indegree(n, 0);

        int maxWeight = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            indegree[v]++;
            maxWeight = max(maxWeight, w);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topoOrder;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            topoOrder.push_back(u);

            for (auto &[v, w] : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        int low = 0;
        int high = maxWeight;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValidPath(n, adj, topoOrder, online, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
