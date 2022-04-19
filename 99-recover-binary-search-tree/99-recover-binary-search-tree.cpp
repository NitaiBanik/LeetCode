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
    
    TreeNode* firstNode = NULL;
    TreeNode* secondNode = NULL;
    TreeNode* previousNode = NULL;
public:
    
    void visit(TreeNode* root){
        if(!root) return;
        
        visit(root->left);
        if(previousNode && previousNode->val > root->val){
            if(firstNode == NULL){
                firstNode = previousNode;
            }
            secondNode = root;     
        }
        
        previousNode = root;
        visit(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        visit(root);
        
        swap(firstNode->val, secondNode->val);
    }
};