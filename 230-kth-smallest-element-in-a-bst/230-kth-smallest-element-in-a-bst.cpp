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
     void visit(TreeNode* root, int k,  priority_queue<int>& pq){
        if(!root) return;
        
        pq.push(root->val);
        
        if(pq.size() > k) pq.pop();
        
        visit(root->left, k, pq);
        visit(root->right, k, pq);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        
        visit(root, k, pq);
        return pq.top();
    }
};