class Solution {
public:
    bool isValidIndex(int r, int c, int& row, int& col){
        return (r>=0 && r < row && c >=0 && c < col);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>>dp(row, vector<int>(col, -1));
        
        for(int i = 0 ; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else{
                    int val1 = 9999999, val2= 9999999;
                    if(isValidIndex(i, j-1, row, col)) val1 = dp[i][j-1];
                     if(isValidIndex(i-1, j, row, col)) val2 = dp[i-1][j];
                    
                    dp[i][j] = grid[i][j] + min(val1, val2);
                }
            }
        }
        
        return dp[row-1][col-1];
        
    }
};