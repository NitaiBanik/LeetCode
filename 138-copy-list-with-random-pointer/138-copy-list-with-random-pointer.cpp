/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* dummy = new Node(-1);
        Node* savedDummy = dummy;

        Node* savedOrginalHead = head;
        while(head){
            Node* temp = new Node(head->val);
            dummy->next = temp;
            dummy = dummy->next;
            head = head->next;
        }
        
        head = savedOrginalHead;
        dummy = savedDummy->next;
        while(head){
            Node* curr = savedOrginalHead;
            int cn = 1;
            
            while(curr != head-> random){
                cn++;
                curr = curr->next;
            }
            
            curr = savedDummy->next;
            int nodeCount = 1;
            while(nodeCount != cn){
                nodeCount++;
                curr = curr->next;
            }
            dummy->random = curr;
            dummy = dummy->next;
            head = head->next;
            
        }
        return savedDummy->next;
    }     
};