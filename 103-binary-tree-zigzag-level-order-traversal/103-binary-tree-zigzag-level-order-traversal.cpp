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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        
        if(!root) return answer;
        
        queue<TreeNode*> Q;
        Q.push({root});
        
        bool isFromLeft = true;
        
        while(!Q.empty()){
            int sz = Q.size();
            vector<int> tempNodes(sz);
            
            for(int i = 0; i < sz; i++){
                auto node = Q.front();
                Q.pop();
                
                int position = isFromLeft ? i : sz - i - 1;
                tempNodes[position] = node->val;
                
               if(node->left) Q.push(node->left);
               if(node->right) Q.push(node->right);
            }
            
            answer.push_back(tempNodes);
            isFromLeft = !isFromLeft;
        }
        
        return answer;
        
    }
};