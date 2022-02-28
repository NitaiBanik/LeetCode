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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<TreeNode*> Q;
        
        Q.push(root);
        
        map<TreeNode*, unsigned long long> level;   
        map<TreeNode*, unsigned long long> nodeValue;

        map<unsigned long long, unsigned long long> firstIndex;
        
        level[root] = 0;     
        nodeValue[root] = 0;
        
        unsigned long long maxWidth = 0;
        
        while(!Q.empty()){
            
            TreeNode* parent = Q.front();
            Q.pop();
            
            if(parent == NULL) continue;
            
            unsigned long long parentLevel = level[parent];
            unsigned long long nodeNumber = nodeValue[parent];
            
            if(firstIndex.find(parentLevel) == firstIndex.end()){
                firstIndex[parentLevel] = nodeNumber;
            }
            
            maxWidth = max(maxWidth, nodeNumber - firstIndex[parentLevel] + 1);    
           
            if(parent->left != NULL){
                Q.push(parent->left);
                level[parent->left] = parentLevel + 1;
                nodeValue[parent->left] = nodeNumber * 2;
            }
            
            if(parent->right != NULL){
                Q.push(parent->right);
                level[parent->right] = parentLevel + 1;
                nodeValue[parent->right] = nodeNumber * 2 + 1;
            }
        }
        return maxWidth;
    }
};