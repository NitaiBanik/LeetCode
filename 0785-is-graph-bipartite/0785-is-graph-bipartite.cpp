class Solution {
private:
    bool bicolorable = true;
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& color){
        
        for(int i = 0; i < graph[node].size(); i++){
            int currentNode = graph[node][i];
            
            if(color[currentNode] == 0){
                if(color[node] == 1)
                    color[currentNode] = 2;
                else 
                    color[currentNode] = 1;
                dfs(currentNode, graph, color);
            }
            if(color[node] == color[currentNode]){
                bicolorable = false;
                return;
            }
        }
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>color(graph.size(), 0);
        
        for(int i = 0;  i < graph.size(); i++){
            if(color[i] == 0){
                color[i] = 1;
                dfs(i, graph, color);
                
                if(bicolorable == false) return false;
            }
        }
        return true;
    }
};