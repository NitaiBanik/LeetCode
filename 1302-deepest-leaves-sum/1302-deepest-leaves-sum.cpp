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
    int maxLevel= 0, sum = 0;
    void dfs(TreeNode* node, int level){
        if(!node) return;
        
        if(level > maxLevel){
            maxLevel = level;
            sum = 0;
        }
        
        if(level == maxLevel)
            sum += node->val;
        
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 1);
        
        return sum;
    }
};