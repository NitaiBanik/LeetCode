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
    int getSize(ListNode* head){
        int sz = 0;
        while(head){
            sz++;
            head = head->next;
        }
        
        return sz;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int size = getSize(head);
        
        int position = k == 0 ? 0: (k % size);
        
        if(!position) return head;
        
        position = size - position;
        
        ListNode* savedHead = head;
        ListNode* curr = head;
        
        int cn = 1;
        while(cn < position){
            curr = curr->next;
            cn++;
        }
        
        ListNode* lastNode = curr;
        ListNode* newHead = curr->next;
        
       // cout<<"lastval = "<<(lastNode->val)<<endl;
        //cout<<"newHeadVal = "<<(newHead->val)<<endl;
        
        
        while(curr->next) curr = curr->next;
        
        curr->next = savedHead;
        lastNode->next = NULL;
        
        return newHead;
    }
};