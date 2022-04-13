class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int l = n, d = n - 1, r = n -1, u = n - 2;
        
        int tot = n * n, cnt = 0;
        int x = 0, y = 0;
        
        while(1){
            for(int i = 1; i <= l; i++){
                ans[x][y++] = ++cnt;
                if(cnt == tot) return ans;
            }
            y--;
            x++;
            for(int i = 1; i <= d; i++){
                ans[x++][y] = ++cnt;
                if(cnt == tot) return ans;
            }
            x--;
            y--;
            for(int i = 1; i <= r; i++){
                ans[x][y--] = ++cnt;
                if(cnt == tot) return ans;
            }
            y++;
            x--;
            for(int i = 1; i <= u; i++){
                ans[x--][y] = ++cnt;
                if(cnt == tot) return ans;
            }   
            //cout<<cnt<<endl;
            
            l-=2; 
            d-=2;
            u-=2;
            r-=2;
            
            x++;
            y++;
            
            /*cout<<l<<" "<<d<<" "<<u<<" "<<r<<endl;
            
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++)
                    cout<<ans[i][j]<<" ";
                cout<<endl;
                }
                */
        }
        
        return ans;
        
    }
};