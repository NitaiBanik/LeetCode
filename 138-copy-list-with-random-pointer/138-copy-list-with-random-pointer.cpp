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
    Node* createNewListWithoutRandom(Node * head, unordered_map<Node*, Node*>& mp){
        Node* dummy = new Node(-1);
        
        Node* savedDummy = dummy;
        while(head){
            Node* temp = new Node(head->val);
            dummy->next = temp;
            dummy = dummy->next;
            mp[head] = dummy;
            head = head->next;
        }
        return savedDummy->next;
    }
    void addRadomNodeInNewList(Node* headOfOldList, unordered_map<Node*, Node*>& mp){
        while(headOfOldList){
            Node* nodeFromNewList = mp[headOfOldList];
            
            Node* randomFromNewList = mp[headOfOldList->random];
            nodeFromNewList->random = randomFromNewList;
            
            headOfOldList = headOfOldList->next;
            
        }
    }
    
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, Node*> mp;
        
        Node* headOfNewList = createNewListWithoutRandom(head, mp);      
        addRadomNodeInNewList(head, mp);
        
        return headOfNewList;
    }     
};