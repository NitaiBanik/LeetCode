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
    
    int sum= 0;
public:
    void convertTree(TreeNode* root){
        
        if(!root) return;
        
        convertTree(root->right);
        
        sum += root->val;
        root->val = sum;
        
        convertTree(root->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        convertTree(root);
        
        return root;
    }
};