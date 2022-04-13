class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        int tot = rows * cols, cnt = 0;
        vector<int> ans(tot, 0);
        
        int r = cols, d = rows - 1, l = cols - 1, u = rows - 2;
        int x = 0, y = 0;
        
        while(1){    
            for(int i = 0; i < r; i++){
                ans[cnt++] = matrix[x][y++];
                 if(cnt == tot) return ans;
            } 
            if(cnt == tot) return ans;
            x++, y--;  
            for(int i = 0; i < d; i++){
                ans[cnt++] = matrix[x++][y];
                 if(cnt == tot) return ans;
            }
            
            x--, y--;
            for(int i = 0; i < l; i++){
                ans[cnt++] = matrix[x][y--]; 
                 if(cnt == tot) return ans;
            }
            
            x--, y++;
            for(int i = 0; i < u; i++){
                ans[cnt++] = matrix[x--][y];
                 if(cnt == tot) return ans;
             }
            
            x++, y++;      
            l-=2, r-=2, u-=2, d-=2;       
        }
        return ans;
    }
};