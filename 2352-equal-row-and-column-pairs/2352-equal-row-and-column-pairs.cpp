class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0, sz = grid[0].size();
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++){
                bool isSame = true;
                
                for(int k = 0; k < sz; k++){
                    if(grid[k][j] != grid[i][k]){
                        isSame = false;
                        break;
                    }
                }
                 ans += isSame;
            }
        }
        
        return ans;
    }
};