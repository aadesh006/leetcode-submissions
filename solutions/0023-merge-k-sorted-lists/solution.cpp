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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>OutputArr;
        for(ListNode* ll : lists){
            while(ll != nullptr){
                OutputArr.push_back(ll->val);
                ll = ll->next;
            }
        }

        if(OutputArr.empty()) return nullptr;
        sort(OutputArr.begin(), OutputArr.end());

        ListNode* newLL = new ListNode(0);
        ListNode* current = newLL;
        for(int i=0; i<OutputArr.size(); i++){
            current->next = new ListNode(OutputArr[i]);
            current = current->next;
        }

        return newLL->next;
    }
};
