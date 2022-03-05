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
    void dfs(TreeNode* root, int lvl, int parent){
        if(!root) return;
        
        int value = root->val;
        par[value] = parent;
        level[value] = lvl;
        
        valueToNode[root->val] = root;
        
        dfs(root->left, lvl + 1, root->val);
        dfs(root->right, lvl + 1, root->val);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* pp, TreeNode* qq) {
        
        int p = pp->val, q = qq->val;
       
        dfs(root, 0, -1);
        if(level[p] > level[q]) swap(p, q);
        
        while(level[p] != level[q]){
            q = par[q];
        }
        
        if(p == q) return valueToNode[p];
        
        while(par[p] != par[q] && p != par[q] && q != par[p]){
            p = par[p], q = par[q];
        }
        
        return valueToNode[par[p]];
    }
};