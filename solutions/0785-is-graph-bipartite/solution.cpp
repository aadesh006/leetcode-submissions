class Solution {
private:
    bool dfs(int node, int currentColor, vector<int>& color, vector<vector<int>>& graph){
        color[node] = currentColor;

        for(int neighbor : graph[node]){
            if(color[neighbor] == 0){
                if (!dfs(neighbor, -currentColor, color, graph)) return false;
            } 
            else if(color[neighbor] == color[node]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for(int i=0; i<n; i++){
            if(color[i] == 0){
                if(!dfs(i, 1, color, graph)) return false;
            }
        }

        return true;
    }
};
