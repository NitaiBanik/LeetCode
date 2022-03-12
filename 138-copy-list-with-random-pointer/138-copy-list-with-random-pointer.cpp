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
        
        map<Node*, Node*> mp;     
        Node* savedOrginalHead = head;
        while(head){
            Node* temp = new Node(head->val);
            dummy->next = temp;
            dummy = dummy->next;
            mp[head] = dummy;
            head = head->next;
        }
        
        head = savedOrginalHead;
        while(head){
            Node* nodeFromNewList = mp[head];
            
            Node* randomFromNewList = mp[head->random];
            nodeFromNewList->random = randomFromNewList;
            
            head = head->next;
            
        }
        return savedDummy->next;
    }     
};