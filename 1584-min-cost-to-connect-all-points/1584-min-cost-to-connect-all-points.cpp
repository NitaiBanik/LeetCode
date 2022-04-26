class Solution {
public:
    vector<int> parent;
    
    int findParent(int a){
        if(parent[a] == a) return a;
        return parent[a] = findParent(parent[a]);
    }
    
    void Union(int a, int b){
        parent[findParent(b)] = findParent(a); 
    }
    
    int calculateMinimumSpanningTree(vector<pair<int, pair<int, int>> >& edges){
        
        int cost = 0;
        for(int i = 0; i< edges.size(); i++){
            int a = findParent(edges[i].second.first);
            int b = findParent(edges[i].second.second);
            
            if(a != b){
                Union(a, b);
                cost += edges[i].first;
            }
        }
        
        return cost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        vector<pair<int, pair<int, int>>> edges;
        
        for(int i = 0 ; i < points.size() - 1; i++)
            for(int j = i + 1; j < points.size(); j++){
                int distance = abs(points[i][0]- points[j][0]) +  abs(points[i][1]- points[j][1]);
                edges.push_back({distance, {i, j}});
            } 
        
        sort(edges.begin(), edges.end());
        
        parent = vector<int>(points.size() + 2);
        for(int i = 0; i <= points.size(); i++)
            parent[i] = i;
        
        return calculateMinimumSpanningTree(edges);
         
    }
};