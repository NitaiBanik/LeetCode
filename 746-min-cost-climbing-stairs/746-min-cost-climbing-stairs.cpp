class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size()][2];
        dp[0][0] = 0;
        dp[0][1] = cost[0];
                
        for(int i = 1; i < cost.size(); i++){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = min(cost[i] + dp[i-1][0], cost[i] + dp[i-1][1]);
            
        }
      return min(dp[cost.size() - 1][0], dp[cost.size() - 1][1]);  
    }
};