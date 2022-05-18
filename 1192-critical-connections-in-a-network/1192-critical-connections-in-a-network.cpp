class Solution {
public:
    vector<vector<int>>answer;
    vector<vector<int>>graph;
    
    vector<int>firstTime, minimumTime, isVisited;
    int time = 1;
    
    void dfs(int node, int parent){
        firstTime[node] = minimumTime[node] = time++;
        isVisited[node] = 1;
        
        for(auto& child: graph[node]){
            if(child == parent) continue;
            
            if(!isVisited[child])
                dfs(child, node);
            
            minimumTime[node] = min(minimumTime[child], minimumTime[node]);
            
            if(firstTime[node] < minimumTime[child])
                answer.push_back({node, child});
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph = vector<vector<int>>(n + 1);
        minimumTime = vector<int>(n + 1);
        isVisited = vector<int>(n + 1, 0);
        firstTime = vector<int>(n + 1);
        
        for(auto edge: connections){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        dfs(0, -1);
        
        return answer;
        
    }
};