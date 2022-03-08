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
    bool hasCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        int max = 999999;
        
        while(slow){
            slow = slow->next;
            if(slow && slow->val == max) return true;
            if(slow)slow->val = max;
        }
        return false;
    }
};