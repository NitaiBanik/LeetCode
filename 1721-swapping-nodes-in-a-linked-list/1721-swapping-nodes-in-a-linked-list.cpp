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
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode* kthNode;
        ListNode* kthNodeFromEnd;
        
        ListNode* currentNode = head;     
        
        int length = 0;
        while(currentNode != NULL)
        {
            length++;
            if(length == k) kthNode = currentNode;
            currentNode = currentNode->next;
        }
        
        currentNode = head;
        for(int i = 1; i<= (length-k); i++)
        {
            currentNode = currentNode->next;
        }
        
        kthNodeFromEnd = currentNode;
        swap(kthNode->val, kthNodeFromEnd->val);
        
        return head;
    }
};