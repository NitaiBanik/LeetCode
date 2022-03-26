class Solution {
public:
    void flatternMatrix(vector<vector<int>>& mat, vector<int>& original){      
        for(int i = 0; i < mat.size(); i++)
            for(int j = 0; j < mat[0].size(); j++)
                original.push_back(mat[i][j]);
    }
    
    void reconstructMatrix(vector<int>& mat, vector<vector<int>>& reshaped, int m, int n){
        int row = 0, col = 0;      
        for(int i = 0; i < mat.size(); i++){
            reshaped[row][col++] = mat[i];
            if(col == n) row++, col = 0;
        }
    }
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int m, int n) {
        
        vector<int>flatternedmatrix;
        flatternMatrix(mat, flatternedmatrix);
        if(flatternedmatrix.size() != (m * n)) return mat;
        
        vector<vector<int>> reshaped(m, vector<int>(n));  
        reconstructMatrix(flatternedmatrix, reshaped, m, n);
        
        return reshaped;
        
    }
};