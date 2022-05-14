class Solution {
public:
    int mx = INT_MIN;
    vector<pair<int, int>> graph[103];
    
    void dfs(int node, int time, vector<int>& visited){
        
        visited[node] = time;
       // mx = max(mx, time);
        
        for(auto edge: graph[node]){
            if(time + edge.second < visited[edge.first])
            dfs(edge.first, time + edge.second, visited);
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> visited(n + 1, INT_MAX);
        
        for(auto edge: times){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        
        dfs(k , 0, visited);
        
        int totalVisited = 0;
        for(int i = 1; i<= n; i++)
            //cout<<visited[i]<<endl;
            totalVisited += (visited[i] != INT_MAX);
        
     //   cout<<"tot = "<<totalVisited<<endl;
        
        for(int i = 1; i<= n; i++)
            mx = max(mx, visited[i]);
        
        
        return totalVisited == n ? mx: -1;
        
    }
};