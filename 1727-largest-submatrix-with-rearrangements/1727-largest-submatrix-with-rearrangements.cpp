class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix[0].size(); i++){
            for(int j = 1; j < matrix.size(); j++)
                if(matrix[j][i] == 1) matrix[j][i] += matrix[j-1][i];
        }
        
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++){
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            
            ans = max(ans, matrix[i][0]);
            
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0) break;
                
              ans = max(ans, matrix[i][j] * (j + 1));
            }
        }     
        return ans;
    }
};