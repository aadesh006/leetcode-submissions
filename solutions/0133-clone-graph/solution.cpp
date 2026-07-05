/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* dfs(Node* current, unordered_map<Node*, Node*>& hashMp){
        vector<Node*> neighborVec;
        Node* clone = new Node(current->val);
        hashMp[current] = clone;

        for(auto i : current->neighbors){
            if(hashMp.find(i)!=hashMp.end()) neighborVec.push_back(hashMp[i]);
            else neighborVec.push_back(dfs(i, hashMp));
        }
        clone->neighbors=neighborVec;
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<Node*, Node*>hashMp;
        if(node->neighbors.size() ==0){
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(node, hashMp);
    }
};
