class Solution {
public:
    vector<int> houses;
    vector<vector<int>> cost;
    
    int dp[105][25][105], target;
    
    int fun(int pos, int prev, int nei){
        if(pos == houses.size()){
            if(nei == target) return 0;
            return INT_MAX/2;
        }
        
        if(nei > target)
            return INT_MAX/2;
        
        if(dp[pos][prev][nei] != -1)
            return dp[pos][prev][nei];
        
        
        int mn = INT_MAX/2;
             
        if(houses[pos] != 0)
            mn = min(mn, fun(pos + 1, houses[pos], nei + (prev !=  houses[pos])));
        else
        for(int i = 0; i < cost[pos].size(); i++){
            mn = min(mn, cost[pos][i] + fun(pos + 1, i + 1, nei + (prev != (i  + 1))));
        }
        
        return dp[pos][prev][nei] = mn;
    }
    
    int minCost(vector<int>& house, vector<vector<int>>& costs, int m, int n, int tar) {
        houses = house;
        cost = costs;
        target = tar;
        
        memset(dp, -1, sizeof(dp));
        int res = fun(0, 0, 0);
        return res >= INT_MAX/2 ? -1 : res;
    }
};