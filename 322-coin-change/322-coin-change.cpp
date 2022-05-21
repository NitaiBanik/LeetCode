class Solution {
public:
    
    int fun(int position, int amount, vector<vector<int>>&dp, vector<int>& coins){
        if(amount < 0) return INT_MAX/2;
        if(position < 0){
            if(amount == 0) return 0;
            return INT_MAX/2;
        }
        
        if(dp[position][amount] !=-1) return dp[position][amount];
        
        int mn = INT_MAX/2;
        
        if(amount-coins[position] >= 0)
        mn = min(mn, 1 + fun(position, amount-coins[position], dp, coins));
        
        mn = min(mn, fun(position - 1, amount, dp, coins));
            
        return dp[position][amount] = mn;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount + 1, -1));
        
        int ans = fun(coins.size() - 1, amount, dp, coins);
        return ans >= INT_MAX/2  ? -1: ans;
    }
};