class Solution {
public:
    vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
       
    int lis(int x, int y, int rows, int columns, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(dp[x][y] != -1) return dp[x][y];
        
        int mx = 1;
        for(auto dir: directions){
            int currentX = x + dir.first;
            int currentY = y + dir.second;
            
            if(currentX < 0 || currentX >= rows || currentY < 0 || currentY >= columns) continue;
            
            if(matrix[currentX][currentY] < matrix[x][y])
                mx = max(mx, 1 + lis(currentX, currentY, rows, columns, matrix, dp) );
        }
        
        return  dp[x][y] =  mx;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(columns, -1));
        int mx = 1;
        
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < columns; j++){
                if(dp[i][j] == -1)
                    lis(i, j, rows, columns, matrix, dp);
                
                mx = max(mx, dp[i][j]);
            }
        
        return mx;
        
    }
};