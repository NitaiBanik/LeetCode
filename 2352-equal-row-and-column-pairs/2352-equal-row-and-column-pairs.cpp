class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid[0].size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                bool isSame = true;
                
                for(int k = 0; k <grid[0].size(); k++){
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