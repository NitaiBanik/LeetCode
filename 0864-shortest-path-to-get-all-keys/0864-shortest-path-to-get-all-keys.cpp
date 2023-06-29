class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        queue<vector<int>> Q;
        unordered_map<char, int> key_number;
        
        int row = grid.size();
        int col = grid[0].size();
        int step = 0;
        
        int key_count = 0;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '@'){
                    Q.push({i, j, 0});
                }
                
                if(islower(grid[i][j])){
                    key_number[grid[i][j]] = key_count++;
                }
            }
        }
        
        
        vector<vector<vector<bool>>>dp(row, vector<vector<bool>>(col, vector<bool>(1 << key_count, false)));
        
        while(!Q.empty()){
            int sz = Q.size();
            for(int p = 0; p < sz; p++){
                auto f = Q.front(); 
                int i = f[0], j = f[1], k = f[2];
                Q.pop();
                
                if(i < 0 || i >= row || j < 0 || j >= col) continue;
                
                if(grid[i][j] == '#' ) continue;
                
                if(isupper(grid[i][j])){
                    if((k & (1 << key_number[tolower(grid[i][j])])) == 0){
                    continue;
                    }
                }
                
                if(islower(grid[i][j])){
                    k |= (1<<key_number[grid[i][j]]);
                }
                
                if(k == ((1 << key_count) - 1)){ return step;}
                
                if(dp[i][j][k]) continue;
                
                dp[i][j][k] = true;
                
                Q.push({i + 1, j, k});
                Q.push({i - 1, j, k});
                Q.push({i, j + 1, k});
                Q.push({i, j -1, k});
                
            }
            step++;
        }
        
        return -1;
    }
};