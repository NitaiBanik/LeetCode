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
    TreeNode* flat(TreeNode* root){
        if(!root) return NULL;
        
        TreeNode* leftChild = flat(root->left);
        TreeNode* rightChild = flat(root->right);
        
        root->left = NULL;
        
        if(leftChild && rightChild){
            root->right = leftChild;
            
            while(leftChild->right) leftChild = leftChild->right;
            
            leftChild->right = rightChild;
        }
        
        else if(leftChild){
            root->right = leftChild;
            leftChild->left = NULL;
        }
        
        else if(rightChild){
            root->right = rightChild;
            
            rightChild->left = NULL;
        }
            
        return root;
    }
    
    void flatten(TreeNode* root) {
        flat(root);
    }
};