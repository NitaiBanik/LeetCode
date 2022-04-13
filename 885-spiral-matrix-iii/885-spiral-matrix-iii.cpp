class Solution {
public:
    bool isValid(int rows, int cols, int r, int c){
        return (r >= 0 && r < rows) && (c >= 0 && c < cols);
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        int r = 1, d = 1, l = 2, u = 2;
        
        int tot = rows * cols, cnt = 0;
        
        
        vector<vector<int>> ans(tot, vector<int>(2, 0));
        ans[cnt++] = {rStart, cStart};
        if(cnt == tot) return ans;
        
        while(1){
            for(int i = 0; i < r; i++){    
                cStart++;
                if(isValid(rows, cols, rStart, cStart)){
                    ans[cnt++] = {rStart, cStart};
                    if(cnt == tot) return ans;
                }
            }
            
            for(int i = 0; i < d; i++){
                rStart++;
                
                 if(isValid(rows, cols, rStart, cStart)){
                    ans[cnt++] = {rStart, cStart};
                    if(cnt == tot) return ans;
                }
            }
            
            for(int i = 0; i < l; i++){
                cStart--;
                
                 if(isValid(rows, cols, rStart, cStart)){
                    ans[cnt++] = {rStart, cStart};
                    if(cnt == tot) return ans;
                }
            }
            
            for(int i = 0; i < u; i++){
                rStart--;
                
               if(isValid(rows, cols, rStart, cStart)){
                    ans[cnt++] = {rStart, cStart};
                    if(cnt == tot) return ans;
                }
            }
            r += 2, d += 2, l += 2, u +=2;
        }
        return ans;
    }
};