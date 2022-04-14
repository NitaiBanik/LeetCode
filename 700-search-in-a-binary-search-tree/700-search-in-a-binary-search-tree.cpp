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
    TreeNode* ans;
    
    void bfs(TreeNode* root, int val){
        if(!root) return;
        
        if(root->val == val){
            ans = root;
            return;
        }
        if(root->left) bfs(root->left, val);
        if(root->right) bfs(root->right, val);
        
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        bfs(root, val);
        return ans;
    }
};