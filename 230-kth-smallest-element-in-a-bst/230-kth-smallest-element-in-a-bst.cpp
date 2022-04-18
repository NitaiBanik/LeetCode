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
    int kthSmallest(TreeNode* root, int kth){
        stack<TreeNode*> stk;
        
        while(1){
            while(root){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            if(kth == 1) return root->val;
            kth--;
            stk.pop();
            root = root->right;
        }
    }
};