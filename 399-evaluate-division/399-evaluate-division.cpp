class Solution {
public:
    map<string, vector<string>> graph;
    map<string, vector<double>> cost;
    
    map<string, bool> visited;
    bool found;
    double value;
    
    void dfs(string from, string to, double currentCost){
        
        if(from == to){
            found = true;
            value = currentCost;
        }
        
        if(found) return;
        
        visited[from] = true;
        
        for(int i = 0; i < graph[from].size(); i++){
            if(visited[graph[from][i]]) continue;
            if(found) return;
            dfs(graph[from][i], to, currentCost * cost[from][i]);
            
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for(int i = 0; i < equations.size(); i++){
            string u = equations[i][0];
            string v = equations[i][1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
            
            cost[u].push_back(values[i]);
            cost[v].push_back((double)1.00/values[i]);
        }
        
        vector<double> ans;
            
        for(int i = 0; i < queries.size(); i++){
            string from = queries[i][0];
            string to = queries[i][1];
            
            if(graph.find(from) == graph.end() || graph.find(to) == graph.end()){
                ans.push_back(-1.00);
            }       
            else{
                found = false;
                visited.clear();
                
                dfs(from, to, 1.00);
                if(found)
                ans.push_back(value);
                else  ans.push_back(-1.00);
            }
            
        }
        
        return ans;
        
    }
};