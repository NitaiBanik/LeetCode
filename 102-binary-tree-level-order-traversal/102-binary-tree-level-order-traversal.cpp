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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>>answer;
        queue<TreeNode*> roots;
        
        roots.push(root);
        
        while(!roots.empty()){
            vector<int> vec;
            int numberOfRoots = roots.size();
            for(int i = 0; i < numberOfRoots; i++){
                TreeNode* top = roots.front();
                roots.pop();
                vec.push_back(top->val);
                
                if(top->left) roots.push(top->left);
                if(top->right) roots.push(top->right);
            }
            answer.push_back(vec);
        }
        return answer;
    }
};