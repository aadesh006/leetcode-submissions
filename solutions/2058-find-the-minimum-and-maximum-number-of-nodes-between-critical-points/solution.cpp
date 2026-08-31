/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>res(2, -1);
        if(!head || !head->next) return res;

        vector<int> criticalIdx;
        ListNode* current = head; 
        int prevNode =current->val; 
        int idx =0;

        while(current != nullptr){ 
            idx++;
            ListNode* nextNode = current->next;
            if (nextNode !=nullptr) {
                if ((current->val >prevNode && current->val >nextNode->val) ||
                    (current->val <prevNode && current->val <nextNode->val)) {
                    criticalIdx.push_back(idx);
                }
            }
            prevNode = current->val; 
            current = current->next; 
        }

        if(criticalIdx.size() >=2){
            int minDist=INT_MAX;
            int maxDist = criticalIdx.back() - criticalIdx.front();
            for(int i=1; i<criticalIdx.size(); i++){
                minDist = min(minDist, criticalIdx[i]-criticalIdx[i-1]);
            }
            res[0]=minDist;
            res[1]=maxDist;
        }
        return res;
    }
};
