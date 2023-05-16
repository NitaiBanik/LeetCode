/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 **/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* temp = head-> next;
        ListNode* prev = new ListNode(-1);
        
        
        while(head != NULL && head->next != NULL )
        {
            printf("head = %d\n", head->val);
            
            ListNode* nextNode = head->next;
            printf("next = %d\n", nextNode->val);
            
            ListNode* nextNextNode = nextNode->next;

            
            nextNode->next = head;
            head->next = nextNextNode;
            
            prev->next = nextNode;
            prev = head;
            head = nextNextNode;   
            

            
        }
        
        return temp;
        
    }
};