class Solution {
    int maximumPossibleCost = 6000 * 6000; 
public:
    vector<vector<int>> buildGraphFromInput(int nodes, vector<vector<int>>& graph, vector<vector<int>>& times){
        for(int node = 1; node <= nodes; node++)
            graph[node][node] = 0;
        
        for(auto edge: times){
            graph[edge[0]][edge[1]] = edge[2];
        }    
        
        return graph;
    }
    
    vector<vector<int>> computeDelayTimesByFloydWarshal(int nodes, vector<vector<int>>& graph){
        for(int middle = 1; middle <= nodes; middle++)
            for(int from = 1; from <= nodes; from++)
                for(int to = 1; to <= nodes; to++)
                    graph[from][to] = min(graph[from][to], graph[from][middle] + graph[middle][to]);
        
        return graph;
    }
    
    int getMaximumDelayTime(int nodes, int startNode, vector<vector<int>>&graph){ 
        int maximumDelayTime = INT_MIN;
        for(int node = 1; node <= nodes; node++){
            if(graph[startNode][node] == maximumPossibleCost) return -1;
            
            maximumDelayTime = max(maximumDelayTime, graph[startNode][node]);
        }
        
        return maximumDelayTime;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {    
        vector<vector<int>>graph(n + 1, vector<int>(n + 1, maximumPossibleCost));
        
        graph = buildGraphFromInput(n, graph, times);
        graph = computeDelayTimesByFloydWarshal(n, graph);
        
        return getMaximumDelayTime(n, k, graph);
        
    }
};