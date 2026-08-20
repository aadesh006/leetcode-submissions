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
    ListNode* sortList(ListNode* head) {
        ListNode* current=head;
        vector<int>output;
        while(current !=nullptr){
            output.push_back(current->val);
            current=current->next;
        }
        sort(output.begin(), output.end());
        current =head;
        int i=0;
        while(current!=nullptr){
            current->val=output[i];
            current=current->next;
            i++;
        }
        return head;
    }
};
