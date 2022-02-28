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
    int getMaxWidth(TreeNode* root){
        
        queue<pair<TreeNode*, unsigned long long>>Q;   
        Q.push({root, 1});
        
        unsigned long long maxNodes = 0;
        
        while(!Q.empty()){
            unsigned long long leftNodeNumber = Q.front().second;
            unsigned long long rightNodeNumber = leftNodeNumber;
            
            int sz = Q.size();
            
            for(int i = 0; i < sz; i++){
                TreeNode* parent = Q.front().first;
                rightNodeNumber = Q.front().second;
                Q.pop();
                
                if(parent->left) Q.push({parent->left, rightNodeNumber * 2});
                if(parent->right) Q.push({parent->right, rightNodeNumber * 2 + 1});
            }
            
            maxNodes = max(maxNodes, rightNodeNumber - leftNodeNumber + 1);
        }
        
        return maxNodes;
    }
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        return getMaxWidth(root);
    }
};