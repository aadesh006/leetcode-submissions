class Solution {
private:
    vector<int> parent;
    vector<int> rank;

    int findNode(int node){
        if(parent[node] ==node) return node;
        return parent[node] =findNode(parent[node]);
    }

    bool unionSets(int node1, int node2){
        int root1 = findNode(node1);
        int root2 = findNode(node2);
        if(root1==root2) return false;

        if(rank[root1] > rank[root2]) parent[root2] =root1; 
        else if(rank[root1] < rank[root2]) parent[root1] =root2; 
        else{
            parent[root2]=root1;
            rank[root1]++;
        }
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);
        for (int i=0; i <parent.size(); i++) {
            parent[i]=i;
        }

        for(auto const& edge : edges){
            int u=edge[0];
            int v=edge[1];

            if(!unionSets(u,v)) return {u, v};
        }
        return {};
    }
};
