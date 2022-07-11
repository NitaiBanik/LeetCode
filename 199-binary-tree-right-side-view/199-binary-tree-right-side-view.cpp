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
    vector<int> vec[105];
    void fun(TreeNode* root, int lvl){
        if(!root) return;
        
        vec[lvl].push_back(root->val);
        
        fun(root->left, lvl + 1);
        fun(root->right, lvl + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        fun(root, 1);
        
        vector<int>answer;
        
        for(int i = 0; i < 100; i++){
            if(vec[i].size() > 0)
            answer.push_back(vec[i][vec[i].size() - 1]);
    }
        return answer;
    }
};