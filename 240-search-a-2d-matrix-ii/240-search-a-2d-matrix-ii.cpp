class Solution {
public:
    int getCol(vector<vector<int>>& matrix, int target){
        
        int col = 0;
        int row = matrix.size()-1;
        
        while(col >= 0 && col < matrix[0].size() && row >= 0 && row < matrix.size()){
            if(matrix[row][col] == target) return true;
            
            if(matrix[row][col] > target) row--;
            else col++;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        bool ans = getCol(matrix, target);
        
        if(ans) return true;
        
        return false;
        
    }
};