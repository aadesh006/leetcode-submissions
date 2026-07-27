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
    bool isPalindrome(ListNode* head) {
        ListNode* current = head;
        vector<int>listArr;
        while(current != nullptr){
            listArr.push_back(current->val);
            current = current->next;
        }
        vector<int> reversed= listArr;
        reverse(reversed.begin(), reversed.end());
        for(int i=0;i<listArr.size(); i++){
            if(reversed[i] != listArr[i]) return false;
        }

        return true;
    }
};
