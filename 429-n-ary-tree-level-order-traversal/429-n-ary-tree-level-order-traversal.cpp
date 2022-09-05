/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> answer;
        
        if(!root) return answer;
        
        queue<Node*> Q;
        Q.push(root);
        
        vector<int> levelNodes;
        
        while(!Q.empty()){
            
            int sz = Q.size();
            while(sz--){
                auto front = Q.front();
                Q.pop();
                
                levelNodes.push_back(front->val);
                
                for(auto child: front->children){
                    Q.push(child);
                }
            }
            
            if(levelNodes.size() == 0) break;
            
            answer.push_back(levelNodes);
            levelNodes.clear();
        }
        return answer;
    }
};