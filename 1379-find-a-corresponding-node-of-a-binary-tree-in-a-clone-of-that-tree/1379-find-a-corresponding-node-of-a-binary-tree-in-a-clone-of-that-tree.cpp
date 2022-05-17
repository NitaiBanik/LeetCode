/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* referenceNode = NULL;
    
    void traverse(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(referenceNode) return;
        if(!original) return;
        
        if(original == target){
            referenceNode = cloned;
            return;
        }
        
        traverse(original->left, cloned->left, target);
        traverse(original->right, cloned->right, target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        traverse(original, cloned, target);
        return referenceNode;
    }
};