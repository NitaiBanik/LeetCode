class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() -1;
        int col = 0;
        
            while(matrix[row][0] > target && row > 0){
                row--;
            }
            
            while(matrix[row][col] < target && col < matrix[0].size() - 1){
                col++;
            }
            
            return matrix[row][col] == target;       
    }
};