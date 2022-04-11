class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int row =  grid.size(), col = grid[0].size();
        
        //k %= grid.size();
        
        while(k--){
            int temp = grid[row-1][col-1];
            for(int i = row-1; i >= 0 ; i--){
                for(int j = col -1; j >= 0; j--){
                    if(i == row -1 && j == col - 1) continue;
                    
                    if(j == col - 1)
                        grid[i + 1][0] = grid[i][j];
                    else
                        grid[i][j + 1] = grid[i][j];
                }
            }
            grid[0][0] = temp;
        }
        return grid;
    }
};