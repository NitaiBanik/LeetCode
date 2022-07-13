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
    pair<int, int> calculateAmount(TreeNode* root){
        if(!root) return {0,0};
        
        pair<int, int> leftAmount = calculateAmount(root->left);
        pair<int, int> rightAmount = calculateAmount(root->right);

        int takingRootAmount = root->val + leftAmount.second + rightAmount.second;
        int notTakingRootAmount = max(leftAmount.first, leftAmount.second) + max(rightAmount.first, rightAmount.second);
        
        return {takingRootAmount, notTakingRootAmount};
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = calculateAmount(root);
        
        return max(ans.first, ans.second);
        
    }
};