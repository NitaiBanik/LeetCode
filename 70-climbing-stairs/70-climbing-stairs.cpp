class Solution {
public:
    int dp[46];
    int ans(int n){
        if(n == 0) return 1;
        if(n < 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = ans(n-1) + ans(n-2);
    }
    
    int climbStairs(int n) {
        
        memset(dp, -1, sizeof(dp));
        return ans(n);
    }
};