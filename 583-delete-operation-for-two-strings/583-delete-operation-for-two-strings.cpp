class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        int dp[sz1 + 1][sz2 + 1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i <= sz1; i++)
            for(int j = 0; j <= sz2; j++){
                if(i == 0 || j  == 0) continue;
                
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        
        return sz1 + sz2 - 2 * dp[sz1][sz2];
    }
};