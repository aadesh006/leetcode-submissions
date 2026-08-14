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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> l1Arr;
        vector<int> l2Arr;

        ListNode* current = l1;
        while(current != nullptr){
            l1Arr.push_back(current->val);
            current = current->next;
        }
        
        current = l2;
        while(current != nullptr){
            l2Arr.push_back(current->val); 
            current = current->next;
        }
        reverse(l2Arr.begin(), l2Arr.end());
        reverse(l1Arr.begin(), l1Arr.end());

        vector<int> resultArr;
        int i = l1Arr.size() - 1;
        int j = l2Arr.size() - 1;
        int carry = 0;
        
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += l1Arr[i];
                i--;
            }
            if (j >= 0) {
                sum += l2Arr[j];
                j--;
            }
            carry = sum / 10;
            resultArr.push_back(sum % 10);
        }

        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        for (int val : resultArr) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        
        ListNode* actualHead = dummyHead->next;
        delete dummyHead;
        return actualHead;
    }
};
