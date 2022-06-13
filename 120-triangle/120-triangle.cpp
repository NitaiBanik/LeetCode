class Solution {
public:
    int dp[202][202];
    int rows;
    
    int fun(int row, int col, vector<vector<int>>& triangle){
        if(row ==rows) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int mn = INT_MAX;
        mn = min(mn, triangle[row][col] + fun(row + 1, col,triangle));
        mn = min(mn, triangle[row][col] + fun(row + 1, col + 1, triangle));
        
        return dp[row][col] = mn;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, sizeof(dp));
        
        rows = triangle.size();
        
        return fun(0, 0, triangle);
    }
};