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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* current = head;
        vector<int> arr;
        while (current != nullptr) {
            arr.push_back(current->val);
            current = current->next;
        }
        
        int n = arr.size();
        swap(arr[k - 1], arr[n - k]);
        current = head;
        int i = 0;
        while (current != nullptr) {
            current->val = arr[i++];
            current = current->next;
        }
        
        return head;
    }
};

