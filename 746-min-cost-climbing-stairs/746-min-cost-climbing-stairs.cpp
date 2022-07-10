class Solution {
public:
    int dp[1005][2];
    
    int fun(int pos, int state, vector<int>& cost){
        if(pos == cost.size())
            return 0;
        
        if(dp[pos][state] != -1) return dp[pos][state];
        
        if(state == 1)
            return dp[pos][state] = cost[pos] + fun(pos + 1, 0, cost);
        else
            return dp[pos][state] = min(cost[pos] + fun(pos + 1, 0, cost), fun(pos + 1, 1, cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, cost);
    }
};