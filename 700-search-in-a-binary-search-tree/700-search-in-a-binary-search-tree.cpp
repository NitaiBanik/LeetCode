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
     TreeNode* bfs(TreeNode* root, int val){
        if(!root) return NULL;
        
        if(root->val == val)
            return root;
         
         TreeNode* ans;
         
         if(root->left)
             ans = bfs(root->left, val);
         
         if(!ans && root->right)
             ans = bfs(root->right, val);
         
        return ans;
        
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
       return bfs(root, val);
    }
};