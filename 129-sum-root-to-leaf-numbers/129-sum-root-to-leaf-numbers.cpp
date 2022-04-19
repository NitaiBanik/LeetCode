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
    int totalSum = 0;
    
    void visit(TreeNode* root, int prev){
        if(!root) return;
        
        if(root->left == NULL && root->right == NULL){
            totalSum += (prev * 10 + root->val);
            return;
        }
        
        visit(root->left, prev * 10 + root->val);
        visit(root->right, prev * 10 + root->val);
    }
    
    int sumNumbers(TreeNode* root) {
        
        visit(root, 0);
        return totalSum;
    }
};