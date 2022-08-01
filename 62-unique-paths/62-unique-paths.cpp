class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> previousRow(n, 1), currentRow(n, 1);
        
         for(int i = 1; i < m; i++){
             for(int j = 1; j < n; j++){
                 currentRow[j] = previousRow[j] + currentRow[j-1];
             }
             swap(previousRow, currentRow);
         }
        
        return previousRow[n-1];
    }
};