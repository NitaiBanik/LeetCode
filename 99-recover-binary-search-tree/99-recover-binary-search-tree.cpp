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
    vector<int>vec;
    int pos;
    
    void visit(TreeNode* root){
        if(!root) return;
        
        visit(root->left);
        vec.push_back(root->val);
        visit(root->right);
    }
    
    void revisit(TreeNode* root){
        if(!root) return;
        
        revisit(root->left);
        root->val = vec[pos++];
        revisit(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        visit(root);
        sort(vec.begin(), vec.end());
        pos = 0;
        revisit(root);
    }
};