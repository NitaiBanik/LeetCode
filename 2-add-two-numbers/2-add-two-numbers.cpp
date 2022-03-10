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
        
        int inHand = 0;
        
        ListNode* sentinal = new ListNode();
        ListNode* currentNode = sentinal;
        
        while(l1 || l2){
            int value1 = 0, value2 = 0;
            
            if(l1) value1 = l1->val, l1 = l1->next;
            if(l2) value2 = l2->val, l2 = l2->next;
            
            int sum = value1 + value2 + inHand;
            inHand = (sum > 9) ? 1 : 0;
            sum %= 10;
            
            ListNode* node = new ListNode(sum);
            currentNode->next = node;
            currentNode = currentNode->next;
        }
        if(inHand){
            ListNode* node = new ListNode(1);
            currentNode->next = node;
        }
        return sentinal->next;
        
    }
};