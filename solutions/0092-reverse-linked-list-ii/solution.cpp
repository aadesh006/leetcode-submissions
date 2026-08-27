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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>nums;
        ListNode* current=head;
        while(current !=nullptr){
            nums.push_back(current->val);
            current=current->next;
        }

        reverse(nums.begin() +(left-1), nums.begin()+right);
        current=head;
        int i=0;
        while(current!=nullptr){
            current->val = nums[i];
            current=current->next;
            i++;
        }
        return head;
    }
};
