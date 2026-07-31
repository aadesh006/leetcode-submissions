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
private:
    ListNode* reverseNextKNodes(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        for (int i = 0; i < k; i++){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (!check) return head;
            check = check->next;
        }
        ListNode* newHead = reverseNextKNodes(head, k);
        head->next = reverseKGroup(check, k);
        return newHead;
    }
};
