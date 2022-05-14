class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> cost(n + 1, INT_MAX);
        
        vector<pair<int, int>> graph[n + 1];
        for(auto edge: times){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        
        priority_queue<pair<int, int>>Q;
        
        Q.push({0, k});
        cost[k] = 0;
        
        while(!Q.empty()){
            pair<int, int> top = Q.top();
            Q.pop();
            for(auto edge: graph[top.second]){
                if(cost[edge.first] > edge.second - top.first){
                    cost[edge.first] =  edge.second - top.first;
                    Q.push({-cost[edge.first], edge.first});
                }
            }
        }
        
        int totalVisited = 0;
        for(int i = 1; i<= n; i++)
            totalVisited += (cost[i] != INT_MAX);
        
        int mx = INT_MIN;
        for(int i = 1; i<= n; i++){
            //cout<<"node = "<<i<<" cost = "<<cost[i]<<endl;
            mx = max(mx, cost[i]);
        }
        
        
        return totalVisited == n ? mx: -1;
        
    }
};