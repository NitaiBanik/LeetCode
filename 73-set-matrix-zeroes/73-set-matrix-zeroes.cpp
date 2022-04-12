class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<int> rows(7, 0);
        vector<int> cols(7, 0);
        
        for(int i = 0;i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                   rows[i/30] |= (1 << (i%30));
                   cols[j/30] |= (1 << (j%30));
                }
            }
        
         for(int r = 0; r < matrix.size(); r++){
             int val = rows[r/30] & (1 << (r%30));
             if(val)
             for(int c = 0; c < matrix[0].size(); c++)
                 if(val) matrix[r][c] = 0;
         }
        
         for(int c = 0; c < matrix[0].size(); c++){
              int val = cols[c/30] & (1 << (c%30));
             if(val)
            for(int r = 0; r < matrix.size(); r++)
                if(val) matrix[r][c] = 0;
            }
        
    }
};