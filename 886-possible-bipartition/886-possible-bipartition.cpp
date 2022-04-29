class Solution {
public:
    vector<int>graph[2001];
    bool bicolorAble = true;
    
    void dfs(int node, vector<int>& color){
        
        for(int i = 0; i < graph[node].size(); i++){
            int currentNode = graph[node][i];
            
            if(color[currentNode] == 0){
                if(color[node] == 1)
                    color[currentNode] = 2;
                else 
                    color[currentNode] = 1;
                dfs(currentNode, color);
            }
            if(color[node] == color[currentNode]){
                bicolorAble = false;
                return;
            }
        }
        
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
         vector<int>color(n + 1, 0);
        
        for(auto edge: dislikes){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        for(int i = 1;  i <= n; i++){
            if(color[i] == 0){
                color[i] = 1;
                dfs(i, color);
                
                if(bicolorAble == false) return false;
            }
        }
        return true;
    }
};