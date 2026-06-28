class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& Output, vector<int>& currentPath, int currentNode){

        int targetNode = grid.size()-1;
        if(currentNode == targetNode){
            Output.push_back(currentPath);
            return;
        }

        for(int neighbor : grid[currentNode]){
            currentPath.push_back(neighbor);
            dfs(grid, Output, currentPath, neighbor);
            currentPath.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> Output;
        vector<int> currentPath;
        currentPath.push_back(0);

        dfs(graph, Output, currentPath, 0);
        return Output;
    }
};
