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
    int rootIndex = 0;
    map<int, int>inorderMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        
        return build(preorder, 0, preorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, int left, int right){
        if(left > right) return NULL;
        
        int rootVal = preorder[rootIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        root->left = build(preorder, left, inorderMap[rootVal] - 1);
        root->right = build(preorder, inorderMap[rootVal] + 1, right);
        
        return root;
    }
};