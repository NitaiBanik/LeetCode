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
        ListNode* previous = NULL;
        ListNode* mainHead = new ListNode(1);
        mainHead->next = head;
        
     for(int i = 1; i < left; i++){
            previous = head;
            head = head->next;
        }

        
        ListNode* nextNode = NULL;
        ListNode* start = previous;
        ListNode* tail = head;
        
        for(int i = 0; i <= right - left; i++){
            nextNode = head->next;
            head->next = previous;
            previous = head;
            head = nextNode;    
        }
        
        if(start)
            start->next = previous;
        else 
          mainHead->next = previous;
        tail->next = head;
        
        return mainHead->next;
    }
};