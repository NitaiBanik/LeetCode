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
    
    unsigned long long maxWidth = 0;
    map<int, unsigned long long> firstIndex;
    
    void dfs(TreeNode* root, int level, unsigned long long nodeNumber){
        if(root == NULL) return;
        
        if(firstIndex.find(level) == firstIndex.end())
            firstIndex[level] = nodeNumber;
        
        maxWidth = max(maxWidth, nodeNumber - firstIndex[level] + 1);
        
        dfs(root->left, level + 1, nodeNumber * 2);
        dfs(root->right, level + 1, nodeNumber * 2 + 1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        return maxWidth;
    }
};