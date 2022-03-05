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
    map<int, int> level, par;
    map<int, TreeNode*> valueToNode;
    void dfs(TreeNode* root, int parent){
        if(!root) return;
        
        int value = root->val;
        par[value] = parent;
        level[value] = level[parent] + 1;
        
        valueToNode[root->val] = root;
        
        dfs(root->left, root->val);
        dfs(root->right, root->val);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* pp, TreeNode* qq) {
        
        int p = pp->val, q = qq->val;
        
        level[root->val] = 0;
       
        dfs(root, -1);
        if(level[p] > level[q]) swap(p, q);
        
        while(level[p] != level[q]){
            q = par[q];
        }
        
        if(p == q) return valueToNode[p];
        
        while(par[p] != par[q]){
            p = par[p], q = par[q];
        }
        
        return valueToNode[par[p]];
    }
};