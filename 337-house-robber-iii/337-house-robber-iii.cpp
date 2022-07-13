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
    map<TreeNode*, map<bool, int>>dp;
    int calculateAmount(TreeNode* root, bool take){
        if(!root) return 0;
        
        if(dp[root][take]) return dp[root][take];
        
        
        if(take)
            return dp[root][take] = max(root->val + calculateAmount(root->left, false) + calculateAmount(root->right, false), calculateAmount(root->left, true) + calculateAmount(root->right, true));
        
       else 
           return dp[root][take] = calculateAmount(root->left, true) + calculateAmount(root->right, true);
    }
    int rob(TreeNode* root) {
        return calculateAmount(root, true);
        
    }
};