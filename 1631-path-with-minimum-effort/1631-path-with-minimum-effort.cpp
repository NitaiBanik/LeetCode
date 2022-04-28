class Solution {
public:
    int fx[4] = {0, 0, +1, -1};
    int fy[4] = {+1, -1, 0, 0};
    
    bool isValid(int x, int y, int r, int c){
        return (x >= 0 && x < r && y >= 0 && y < c);
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        vector<vector<int>> costs(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        
        priority_queue<pair<int, pair<int, int>>> pq;
        
        pq.push({0, {0, 0}});
        
        while(!pq.empty()){
            pair<int, pair<int, int>> top = pq.top();
            pq.pop();
            
            if(-top.first > costs[top.second.first][top.second.second])
                continue;
            
            costs[top.second.first][top.second.second] = -top.first;
            
            if(top.second.first == heights.size() -1 && top.second.second == heights[0].size() -1)
                break;
            
            for(int i = 0; i < 4; i++){
                
                int currentRow = top.second.first + fx[i];
                int currentCol = top.second.second + fy[i];
                
                if(isValid(currentRow, currentCol, heights.size(), heights[0].size())){
                    
                    int cost = max(-top.first, abs(heights[currentRow][currentCol] - heights[top.second.first][top.second.second]));
                    
                    if(cost < costs[currentRow][currentCol])
                    {
                         costs[currentRow][currentCol] = cost;
                         pq.push({-costs[currentRow][currentCol], {currentRow, currentCol}});
                    }
                }
            }
            
            
        }
        
        return costs[heights.size() -1][heights[0].size() -1];
        
    }
};