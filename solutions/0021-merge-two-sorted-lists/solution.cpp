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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { 
        if (list1 == nullptr && list2 == nullptr) return nullptr;

        ListNode* current = list1; 
        vector<int> arr; 
        
        while(current != nullptr){ 
            arr.push_back(current->val); 
            current = current->next; 
        } 
        current = list2; 
        while(current != nullptr){ 
            arr.push_back(current->val); 
            current = current->next; 
        } 

        if (arr.empty()) return nullptr;
        sort(arr.begin(), arr.end()); 
        
        ListNode* newHead = new ListNode(arr[0]); 
        ListNode* tail = newHead;
        
        for(int i = 1; i < arr.size(); i++){
            tail->next = new ListNode(arr[i]);
            tail = tail->next;
        } 
        return newHead; 
    } 
};

