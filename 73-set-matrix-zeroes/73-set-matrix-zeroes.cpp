class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //int row = 0, col = 0;
        
        vector<int> rows(matrix.size(), 0);
        vector<int> cols(matrix[0].size(), 0);
        
        for(int i = 0;i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                   // row |= (1 << i);
                   // col |= (1<<j);
                }
            }
        
         for(int r = 0; r < matrix.size(); r++){
             int val = rows[r];
             for(int c = 0; c < matrix[0].size(); c++)
                 if(val) matrix[r][c] = 0;
         }
        
         for(int c = 0; c < matrix[0].size(); c++){
             int val = cols[c];
            for(int r = 0; r < matrix.size(); r++)
                if(val) matrix[r][c] = 0;
            }
        
    }
};