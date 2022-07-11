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
            
            int sz = Q.size();
            
            Node* prev = NULL;
            
            for(int i = 0; i < sz; i++){
                Node* front = Q.front();
                
                Q.pop();
                
                if(prev){
                    prev->next = front;
                }
                prev = front;
                
                if(front->left)
                    Q.push(front->left);
                
                if(front->right)
                    Q.push(front->right);
            }
            
            prev->next=NULL;
            
            
        }
        return root;
    }
};