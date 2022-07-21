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
    int size = 0;
    ListNode* mainHead;
    Solution(ListNode* head) {
        mainHead = head;
        while(head){
            size++;
            head = head->next;
        }
    }
    
    int getRandom() {
        ListNode* temp = mainHead;
        
        int pos = rand() % size;
        while(pos--)
            temp = temp->next;
        
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */