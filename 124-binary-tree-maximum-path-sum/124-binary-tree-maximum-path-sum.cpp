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
    int maximum = INT_MIN;
    int visit(TreeNode* root){
        if(!root) return 0;
        
        int leftSum = max(0, visit(root->left));
        int rightSum = max(0, visit(root->right));
        maximum = max(maximum, leftSum + rightSum + root->val);
        
        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        visit(root);
        return maximum;
    }
};