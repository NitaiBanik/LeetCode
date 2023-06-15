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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> Q;
       if(root) Q.push(root);
        int mx = INT_MIN, level = 1, x = 1;
        while(!Q.empty()){
            int sum = 0, sz = Q.size();
            for(int i = 0; i < sz; i++){
                auto topp = Q.front();
                Q.pop();
                sum += topp->val;
                
                if(topp->left) Q.push(topp-> left);
                if(topp->right) Q.push(topp-> right);
            }
            
           if(mx < sum){
               mx = sum;
               level = x;
           }
            x++;
        }
        return level;
    }
};