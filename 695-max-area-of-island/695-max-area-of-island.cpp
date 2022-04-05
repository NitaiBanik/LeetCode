class Solution {
public:
    int vis(vector<vector<int>>&grid, int x, int y){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||grid[x][y] == 0) return 0;
        
        grid[x][y] = 0;
        
        return 1 + vis(grid, x + 1, y) + vis(grid, x - 1, y) + vis(grid, x, y  + 1) + vis(grid, x, y - 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1)
                    ans = max(ans, vis(grid, i, j));
        
        return ans;
        
    }
};