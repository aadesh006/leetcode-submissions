class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        vector<vector<int>>adjList(numCourses);
        vector<int>InDegree(numCourses);

        for(int i=0; i<preq.size();i++){
            int target = preq[i][0];
            int required = preq[i][1];

            adjList[required].push_back(target);
            InDegree[target]++;
        }

        queue<int>q;
        for(int i=0; i<numCourses;i++){
            if(InDegree[i] == 0){
                q.push(i);
            }
        }

        int coursesTaken =0;
        while(!q.empty()){
            int currentCourse = q.front();
            q.pop();
            coursesTaken++;
            for(int neighbor : adjList[currentCourse]){

                InDegree[neighbor]--;
                if(InDegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        return coursesTaken == numCourses;        
    }
};
