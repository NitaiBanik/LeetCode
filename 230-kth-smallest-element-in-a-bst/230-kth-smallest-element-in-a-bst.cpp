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
    int val,k;
     void visit(TreeNode* root){
        if(!root) return;
        
        visit(root->left);
        k--;
        if(k == 0) val = root->val;
        visit(root->right);
        
    }
    int kthSmallest(TreeNode* root, int kth){
        k = kth;
        visit(root);
        return val;
    }
};