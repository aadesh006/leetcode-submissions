/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>result;
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> currentLevel;
            for(int i=0; i<levelSize; i++){
                Node* current = q.front(); 
                q.pop();
                if (current == nullptr) continue;
                currentLevel.push_back(current->val);
                for (Node* child : current->children) {
                    if (child != nullptr) q.push(child);
                }
            }
            if (!currentLevel.empty()) {
                result.push_back(currentLevel);
            }
        }
        return result;
    }
};
