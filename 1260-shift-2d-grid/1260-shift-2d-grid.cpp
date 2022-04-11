class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>>ans(grid.size(), vector<int>(grid[0].size(),0));
        
        int row = grid.size(), col = grid[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int newCol = (j + k) % col;
                int newRow = (j + k) / col;
                newRow = (i + newRow) % row; 
                ans[newRow][newCol] = grid[i][j];
            }
        }
        
        return ans;
    }
};