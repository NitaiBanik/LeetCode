class Solution {
public:
    bool bicolorAble = true;
    void dfs(int node, vector<vector<int>>& graph, vector<int>& color, vector<bool>& visited){
        visited[node] = 1;
        
        for(int i = 0; i < graph[node].size(); i++){
            int currentNode = graph[node][i];
            
            if(visited[currentNode] == 0){
                if(color[node] == 1)
                    color[currentNode] = 2;
                else 
                    color[currentNode] = 1;
                dfs(currentNode, graph, color, visited);
            }
            if(color[node] == color[currentNode]){
                bicolorAble = false;
                return;
            }
        }
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>color(graph.size(), 0);
        vector<bool>visited(graph.size(), 0);
        
        for(int i = 0;  i < graph.size(); i++){
            if(color[i] == 0){
                color[i] = 1;
                dfs(i, graph, color, visited);
                
                if(bicolorAble == false) return false;
            }
        }
        return true;
    }
};