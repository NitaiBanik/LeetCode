class Solution {
public:
    int fx[8] = {0, 0, -1, -1, -1, +1, +1, +1};
    int fy[8] = {+1, -1, -1, 0, +1, -1, 0, +1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] == 1) return -1;
        
        int row = grid.size();
        int col = grid[0].size();
        
         vector<vector<int>>cost(row, vector<int>(col, -1));
        
        queue<pair<int, int>>Q;
        Q.push({0, 0});
        cost[0][0] = 1;
        grid[0][0] = 1;
        
        while(!Q.empty()){
            pair<int, int> top = Q.front();
            Q.pop();
            
            if((top.first == row - 1) && (top.second == col - 1))
                return cost[top.first][top.second];
            
            for(int i = 0; i< 8; i++){
                int xx = top.first + fx[i];
                int yy = top.second + fy[i];
                
                if(xx < 0 || xx >= row || yy < 0 || yy >= col || grid[xx][yy] == 1) continue;
                
                grid[xx][yy] = 1;
                
                cost[xx][yy] = cost[top.first][top.second] + 1;
                
                Q.push({xx, yy});
                
            }
        }
        return -1;
        
    }
};