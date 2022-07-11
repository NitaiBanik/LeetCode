/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) { 
       if(!root) return {};
        
       queue<TreeNode*> Queue;
       Queue.push(root);
        
        vector<int>answer;

        while(!Queue.empty()){
            int sz = Queue.size();
            for(int i = 0; i < sz; i++){
                TreeNode* front = Queue.front();
                Queue.pop();
                
                if(i == sz - 1)
                    answer.push_back(front->val);
                
                if(front->left)
                    Queue.push(front->left);
                
                if(front->right)
                    Queue.push(front->right);
            }
        }
        
        return answer;
    }
};