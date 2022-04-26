class Solution {
public:
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>> heap;
        int totalPoints = points.size();
        
        vector<bool> visited(totalPoints);
        
        heap.push({0,0});
        
        int totalCost = 0, edgeCount = 0;
        
        while(edgeCount < totalPoints){
            
            pair<int,int>top = heap.top();
            heap.pop();
            int cost = top.first;
            int currentNode = top.second;
            
            if(visited[currentNode]) continue;
            
            visited[currentNode] = true;
            totalCost += -cost;
            
            edgeCount++;
            
            for(int i = 0; i < totalPoints; i++){
                if(visited[i]) continue;
                
                int weight = abs(points[currentNode][0] - points[i][0]) +  abs(points[currentNode][1] - points[i][1]);
                
                heap.push({-weight, i});
            }
            
        }
        
        return totalCost;
         
    }
};