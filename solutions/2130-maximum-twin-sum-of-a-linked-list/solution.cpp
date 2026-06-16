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
    int pairSum(ListNode* head) {
        vector<int> values;
        ListNode* current = head;
        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }

        int maxTwinSum = 0;
        int n = values.size();
        for (int i = 0; i < n / 2; i++) {
            int currentTwinSum = values[i] + values[n - 1 - i];
            
            if (maxTwinSum <= currentTwinSum) {
                maxTwinSum = currentTwinSum;
            }
        }

        return maxTwinSum;

    }
};
