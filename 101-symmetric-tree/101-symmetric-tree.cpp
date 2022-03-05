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
    bool ans = true;
    void dfs(TreeNode* le, TreeNode* rt){
        
      //  cout<<le->val<<" "<<rt->val<<endl;
        
        if(!le && !rt) return;
        if(!rt || !le){ans = false; return;}
        if(le->val != rt->val){ans = false; return;}
        
        dfs(le->left, rt->right);
        dfs(le->right, rt->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return false;
        dfs(root->left, root->right);
        return ans;
    }
};