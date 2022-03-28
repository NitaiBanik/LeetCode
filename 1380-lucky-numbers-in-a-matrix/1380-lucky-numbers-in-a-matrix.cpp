class Solution {
public:
    int getMinCol(vector<int>& vec){
        int mn = INT_MAX / 3, col = -1;
        
        for(int i = 0; i < vec.size(); i++){
            if(vec[i] < mn){
                mn = vec[i];
                col = i;
            }
        }
        return col;
    }
    
    int getMaxRow(vector<vector<int>>& matrix,int col){
        
        int mx = -1, row = -1;
        
        for(int i = 0; i < matrix.size(); i++){
            
            if(matrix[i][col] > mx){
                mx = matrix[i][col];
                row = i;
            }
        }
        
        return row;
    }
    
    vector<int> luckyNumbers (vector<vector<int>>& matrix) { 
        
        vector<int> ans;
        for(int i = 0; i < matrix.size(); i++){
            int col = getMinCol(matrix[i]);
            int row = getMaxRow(matrix, col);
            
            if(matrix[i][col] == matrix[row][col])
                ans.push_back(matrix[i][col]);
        }
        
        return ans;
        
    }
};