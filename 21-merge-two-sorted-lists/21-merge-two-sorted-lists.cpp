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
        ListNode* head = new ListNode(-1);
        ListNode* savedHaed = head;
        ListNode* temp = new ListNode(-1);
        
        int x = 6;
        while(list1 != NULL || list2 != NULL){
            if(!list1){
                temp = list2;
                list2 = list2->next;
            }
            
            else if(!list2){
                temp = list1;
                list1 = list1->next;
            }
            
             else if(list1-> val > list2->val){
                temp = list2;
                list2 = list2->next;
            }
            
            else {
                temp = list1;
                list1 = list1->next;
            }
            
            head->next = temp;
            head = head->next;
        }
        return savedHaed->next;
    }
};