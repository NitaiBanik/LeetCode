class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high + 1);
        
        dp[0] = 1;
        
        for(int i = 0; i <= high; i++){
           if(i >= zero) dp[i] += dp[i - zero] % 1000000007;
           if(i >= one) dp[i] += dp[i - one] % 1000000007;
        }
        
        long long ans = 0LL;
         for(int i = low; i <= high; i++)
             ans = (ans + dp[i]) % 1000000007;;
        
        return ans;
    }
};