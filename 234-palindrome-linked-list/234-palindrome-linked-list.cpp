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
    ListNode* dummyHead;
    bool isPalindrome(ListNode* head) {
        dummyHead = head;
        
        return isPalinDromeList(head);
    }
    
    bool isPalinDromeList(ListNode* head){
        if(!head) return true;
        
        bool answer = isPalinDromeList(head->next) && (head->val  == dummyHead->val);
        dummyHead = dummyHead->next;
        return answer;
    }
};