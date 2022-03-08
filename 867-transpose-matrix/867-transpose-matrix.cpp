class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix[0].size());
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0 ; j < col; j++)
                ans[j].push_back(matrix[i][j]);
        }
        
        return ans;
    }
};