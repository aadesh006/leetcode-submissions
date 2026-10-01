class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n<=1) return 0;
        int targetMask=(1<<n)-1;

        queue<pair<int,int>>q;
        vector<vector<bool>>visited (n, vector<bool>(1<<n, false));
        for(int i=0; i<n; i++){
            int initialMask =(1<<i);
            q.push({i, initialMask});
            visited[i][initialMask]=true;
        }
        int steps= 0;

        while (!q.empty()) {
            int Size =q.size();
            
            while (Size--) {
                auto [currNode, currMask] =q.front();
                q.pop();
                
                if (currMask==targetMask) return steps;
                
                for (int neighbor:graph[currNode]) {
                    int nextMask =currMask | (1<<neighbor);

                    if (!visited[neighbor][nextMask]) {
                        visited[neighbor][nextMask] = true;
                        q.push({neighbor, nextMask});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};
