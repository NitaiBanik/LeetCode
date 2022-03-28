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
    
    int getMaxValueFromRows(vector<vector<int>>& matrix,int col){
        
        int mx = -1;
        
        for(int i = 0; i < matrix.size(); i++)
            mx = max(mx, matrix[i][col]);
        
        return mx;
    }
    
    vector<int> luckyNumbers (vector<vector<int>>& matrix) { 
        
        vector<int> ans;
        for(int i = 0; i < matrix.size(); i++){
            int col = getMinCol(matrix[i]);
            int max = getMaxValueFromRows(matrix, col);
            
            if(matrix[i][col] == max)
                ans.push_back(max);
        }
        
        return ans;
        
    }
};