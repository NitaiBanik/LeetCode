class Solution {
public:
    long long fun(int pos, int low, int high, int zero, int one, vector<int>&dp){
        if(pos > high) return 0;
        
       if(dp[pos] != -1) return dp[pos];
        
        long long ans = 0;
        
        if(pos >= low && pos <= high) ans = 1LL;
        
        ans += fun(pos + zero, low, high, zero, one, dp);
        ans += fun(pos + one, low, high, zero, one, dp);
        ans %= 1000000007;
        
       // cout<<pos<<" ans = "<<ans<<endl;
        
        return dp[pos] = ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high + 1, -1);
        
        return fun(0, low, high, zero, one, dp);
    }
};