class Solution {
public:
    map<int, int> mp;
    vector<int>graph[105];
    bool vis[105];
    
    void dfs(int node,int src){
        vis[node] = true;
        mp[src]++;
        
        for(int i = 0; i < graph[node].size(); i++)
            if(!vis[graph[node][i]])
            dfs(graph[node][i], src);
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        for(int i = 0; i < bombs.size(); i++){
            for(int j = 0; j < bombs.size(); j++){
                if(i == j) continue;
                long long disX = (bombs[i][0] - bombs[j][0]);
                disX *= disX;
                
                long long disY = (bombs[i][1] - bombs[j][1]);
                disY *= disY;
                
                double diss = (double)sqrt((disX + disY));
                
                if(diss <= (double)bombs[i][2])
                    graph[i].push_back(j);
            }
        }
        
        for(int i = 0; i < bombs.size(); i++){
            memset(vis, 0, sizeof(vis));
                dfs(i, i);
        }
        
        int mx = 0;
        for(int i = 0; i < bombs.size(); i++)
            mx = max(mx, mp[i]);
        return mx;
    }
};