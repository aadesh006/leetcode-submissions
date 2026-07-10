class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n, false);
        int provinceCount=0;

        vector<vector<int>>adjList(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjList[i].push_back(j);
                }
            }
        }

        for(int i=0; i<n; i++){
            if(!visited[i]){
                provinceCount++;

                queue<int>q;
                q.push(i);
                visited[i] = true;

                while(!q.empty()){
                    int u = q.front();
                    q.pop();

                    for(int neighbor : adjList[u]){
                        if(!visited[neighbor]){
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return provinceCount;
    }
};
