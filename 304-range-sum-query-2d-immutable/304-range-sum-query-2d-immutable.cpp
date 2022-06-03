class NumMatrix {
public:
    int dp[205][205];
    NumMatrix(vector<vector<int>>& matrix) {
       if (matrix.size() == 0 || matrix[0].size() == 0) return;
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                dp[i][j + 1] = dp[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++)
            sum += dp[i][col2 + 1] - dp[i][col1];
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */