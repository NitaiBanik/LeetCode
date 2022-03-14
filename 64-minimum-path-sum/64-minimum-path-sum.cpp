class Solution {
public:
    int maxValue = 5000000;
    bool isWithInBoundary(int currentRow, int currentCol, int row, int col){
        if(currentRow < 0 || currentRow == row) return false;
        if(currentCol < 0 || currentCol == col) return false;
        return true;
    }
    
    int fun(int currentRow, int currentCol, int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(currentRow == (row - 1) && currentCol == col) return 0;
        if(currentRow == row && currentCol == (col - 1)) return 0;
        
        
        if(isWithInBoundary(currentRow, currentCol, row, col) == false) return maxValue;
        
        if(dp[currentRow][currentCol] != -1) return dp[currentRow][currentCol];
        
        int val1 = grid[currentRow][currentCol] + fun(currentRow + 1, currentCol, row, col, grid, dp);
        int val2 = grid[currentRow][currentCol] + fun(currentRow, currentCol + 1, row, col, grid, dp);
        
        return dp[currentRow][currentCol] = min(val1, val2);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
       // if(grid.size() == 0) return 0;
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>>dp(row, vector<int>(col, -1));
        
        return fun(0, 0, row, col, grid, dp);
        
    }
};