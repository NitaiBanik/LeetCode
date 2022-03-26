class Solution {
public:
    void reconstructMatrix(vector<vector<int>>& mat, vector<vector<int>>& reshaped, int m, int n){
        int row = 0, col = 0;      
        for(int i = 0; i < mat.size(); i++) 
            for(int j = 0; j < mat[0].size(); j++){
                reshaped[row][col++] = mat[i][j];
                if(col == n) row++, col = 0;
            }
    }
    
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int m, int n) {

        if((mat.size() * mat[0].size()) != (m * n)) return mat;
        
        vector<vector<int>> reshaped(m, vector<int>(n));  
        reconstructMatrix(mat, reshaped, m, n);
        
        return reshaped;
        
    }
};