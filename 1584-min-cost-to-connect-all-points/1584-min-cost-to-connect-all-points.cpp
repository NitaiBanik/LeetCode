class Solution {
public:
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int totalPoints = points.size();
        vector<int>pointCost(totalPoints, INT_MAX);
        
        vector<bool> visited(totalPoints);
        
        pointCost[0] = 0;
        
        int totalCost = 0, edgeCount = 0;
        
        while(edgeCount < totalPoints){
            int currnetPointCost = INT_MAX, currentPoint;
            
            for(int i = 0; i < totalPoints; i++){
                if(visited[i] == false && pointCost[i] < currnetPointCost){
                    currentPoint = i;
                    currnetPointCost = pointCost[i];
                }
            }
            
            visited[currentPoint] = true;
            totalCost += currnetPointCost;
            edgeCount++;
            
            
            
            for(int i = 0; i < totalPoints; i++){
                if(visited[i]) continue;
                
                int weight = abs(points[currentPoint][0] - points[i][0]) +  abs(points[currentPoint][1] - points[i][1]);
                
               if(pointCost[i] > weight)
                   pointCost[i]= weight;
            }
            
        }
        
        return totalCost;
         
    }
};