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
    ListNode* reverseList(ListNode* head) {
        ListNode* reverseHead = NULL;
        ListNode* currentNode = head;
        ListNode* next;
        while(currentNode){
            next = currentNode->next;
            currentNode->next = reverseHead;
            reverseHead = currentNode;
            currentNode = next;
        }
        return reverseHead;
        
    }
};