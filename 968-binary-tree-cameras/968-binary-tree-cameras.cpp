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
    int answer = 0;
    void visitNodes(TreeNode* node, TreeNode* parent, set<TreeNode*>& coveredNodes){
        if(!node) return;
        
        visitNodes(node->left, node, coveredNodes);
        visitNodes(node->right, node, coveredNodes);
        
        if((!parent && coveredNodes.find(node) == coveredNodes.end()) ||
           coveredNodes.find(node->left) == coveredNodes.end() || 
           coveredNodes.find(node->right) == coveredNodes.end()){
            answer++;
            coveredNodes.insert(node);
             coveredNodes.insert(parent);
             coveredNodes.insert(node->left);
             coveredNodes.insert(node->right);
        }
    }
    int minCameraCover(TreeNode* root) {
        set<TreeNode*> coveredNodes;
        coveredNodes.insert(NULL);
        
        visitNodes(root, NULL, coveredNodes);
        return answer;   
        
    }
};