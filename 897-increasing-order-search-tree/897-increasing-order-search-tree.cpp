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
    stack<int> st;
    
    void tarverseBST(TreeNode* root){
        if(!root) return;
        
        tarverseBST(root->right);
        st.push(root->val);
        tarverseBST(root->left);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        tarverseBST(root);
        
        TreeNode* par = new TreeNode(-1);
        TreeNode* temp = par;
        
       while(!st.empty()){
           TreeNode* next = new TreeNode(st.top());
           temp->right = next;
           temp = temp->right;
           st.pop();
       }
        
        return par->right;
    }
};