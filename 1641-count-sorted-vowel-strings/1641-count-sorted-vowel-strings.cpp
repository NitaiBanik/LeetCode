class Solution {
public:
    int fun(int n, int vowel, vector<vector<int>>& dp){
        if(n == 1) return vowel;
        if(vowel == 1) return 1;
        
        if(dp[n][vowel] != - 1) return dp[n][vowel];
        
        return dp[n][vowel] = fun(n-1, vowel, dp) + fun(n, vowel  - 1, dp);
    }
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(6, -1));
        
        return fun(n, 5, dp);
        
    }
};