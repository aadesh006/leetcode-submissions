/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        ListNode* current = head;
        
        while (current != nullptr) {
            if (set.count(current)) return current;
            set.insert(current);
            current = current->next;
        }
        return nullptr;
    }
};

