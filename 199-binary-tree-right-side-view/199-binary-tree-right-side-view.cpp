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
    vector<int> vec;
    void fun(TreeNode* root, int lvl){
        if(!root) return;
        
        if(vec.size() < lvl) vec.push_back(root->val);
        
        fun(root->right, lvl + 1);
        fun(root->left, lvl + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        fun(root, 1);
        return vec;
    }
};