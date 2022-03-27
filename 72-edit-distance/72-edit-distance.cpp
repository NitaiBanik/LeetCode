class Solution {
public:
    int lcs(vector<vector<int>>& dp, string& word1, string& word2, int i, int j){
        if(i == word1.size() || j == word2.size())
            return (word1.size() - i) + (word2.size() - j);
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX/5;
        
        if(word1[i] == word2[j])
            ans = min(ans, lcs(dp, word1, word2, i + 1, j + 1));
        
         ans = min(ans, 1 + lcs(dp, word1, word2, i + 1, j + 1));
         ans = min(ans, 1 + lcs(dp, word1, word2, i, j + 1));
         ans = min(ans, 1 + lcs(dp, word1, word2, i + 1, j));
        
        return dp[i][j] = ans;
        
    }
    int minDistance(string word1, string word2) {
        
        vector<vector<int>>dp(word1.size(), vector<int>(word2.size(), -1));
        
        return lcs(dp, word1, word2, 0, 0);
        
    }
};