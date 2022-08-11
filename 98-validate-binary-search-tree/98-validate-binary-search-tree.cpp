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
    TreeNode* previous= NULL;
    
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
    
    bool inorder(TreeNode* root) {
        if(!root) return true;
        if(!inorder(root->left)) return false;
        
        if(previous != NULL && root->val <= previous->val) return false;
        
        previous = root;
        return inorder(root->right);
    }
};