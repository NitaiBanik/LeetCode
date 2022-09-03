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
        
        queue<TreeNode*> Q;
        Q.push({root});
        
        bool isFromLeft = false;
        
        while(!Q.empty()){
            int sz = Q.size();
            vector<int> tempNodes;
            for(int i = 0; i < sz; i++){
                auto node = Q.front();
                Q.pop();
                if(!node) continue;
                tempNodes.push_back(node->val);
                
                Q.push(node->left);
                Q.push(node->right);
            }
            
            if(tempNodes.size())
            answer.push_back(tempNodes);
            isFromLeft = !isFromLeft;
        }
        
        for(int i = 1; i < answer.size(); i+=2)
            reverse(answer[i].begin(), answer[i].end());
        
        return answer;
        
    }
};