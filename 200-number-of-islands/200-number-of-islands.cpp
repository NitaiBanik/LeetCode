class Solution {
public:
    bool isValidGrid(vector<vector<char>>& grid, int row, int col){
        if(row >= 0 && row < grid.size() && col >= 0 & col < grid[0].size() && grid[row][col] == '1')
            return true;
        
        return false;
    }
    void visit(vector<vector<char>>& grid, int row, int col){
        if(isValidGrid(grid, row, col) == false) return;
        
        grid[row][col] = '0';
        
        visit(grid, row, col + 1);
        visit(grid, row, col - 1);
        visit(grid, row + 1, col);
        visit(grid, row - 1, col);
        
        
    }

    int numIslands(vector<vector<char>>& grid) {    
        int numberofIslands = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1')
                {
                   numberofIslands++;
                    visit(grid, i, j);
                }
            }
        }
        return numberofIslands;
    }
};