/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node*> Q;
        
        Q.push(root);
        
        while(!Q.empty()){
            int size = Q.size();
            
            Node* dummy = new Node(-1);
            while(size--){
                Node* parent = Q.front();
                Q.pop();
                
                dummy->next=parent;
                dummy = dummy->next;
                
                if(parent->left)
                    Q.push(parent->left);
                
                 if(parent->right)
                    Q.push(parent->right);
            }
        }
        return root;
    }
};