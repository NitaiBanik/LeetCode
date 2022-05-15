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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        
        if(!root) return sum;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()){
            int sz = Q.size();
            int levelSum = 0;
            while(sz--){
                TreeNode* frnt = Q.front();
                Q.pop();
                levelSum += frnt->val;
                
                if(frnt->left) Q.push(frnt->left);
                if(frnt->right) Q.push(frnt->right);
                
            }
            sum = levelSum;
        }
        return sum;
    }
};