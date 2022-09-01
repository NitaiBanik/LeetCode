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
    int visit(TreeNode* node, int mx){
        if(!node) return 0;
        
        int count = 0;
        count += mx <= node->val;
        mx = max(mx, node->val);
        
        count += visit(node->left, mx);
        count += visit(node->right, mx);
        
        return count;
    }
    
    int goodNodes(TreeNode* root) {
        return visit(root, INT_MIN);
        
    }
};