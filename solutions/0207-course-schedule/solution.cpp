class Solution {
private:
    bool hasCycle(int node, vector<vector<int>>& adjList, vector<int>& state){
        if(state[node] == 1) return true;
        if(state[node] == 2) return false;

        state[node] = 1;
        for(int neighbor : adjList[node]){
            if(hasCycle(neighbor, adjList, state)) return true;
        }

        state[node] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        vector<vector<int>>adjList(numCourses);
        vector<int> state (numCourses, 0);

        for(auto& pre : preq){
            adjList[pre[1]].push_back(pre[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(state[i] == 0){
                if(hasCycle(i, adjList, state)) return false;
            }
        }
        return true;
    }
};
