class Solution {
private:
    bool hasCycle(int node, vector<vector<int>>& adjList, vector<int>& state, vector<int>& result){

        if(state[node] == 1) return true;
        if(state[node] == 2) return false;

        state[node] = 1;
        for(int neighbor : adjList[node]){
            if(hasCycle(neighbor, adjList, state, result)){
                return true;
            }
        }

        state[node] = 2;
        result.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        vector<vector<int>> adjList(numCourses);
        vector<int> result;
        vector<int> state(numCourses, 0);

        for(auto& pre : preq){
            adjList[pre[1]].push_back(pre[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(state[i] == 0){
                if(hasCycle(i, adjList, state, result)){
                    return {};
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
