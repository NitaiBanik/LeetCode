class Solution {
public:
    int dp[505][505];
    string f, s;
    int lcs(int p, int q){
        if(p == f.size())
            return 0;
        
         if(q == s.size())
            return 0;
        
        if(dp[p][q] != -1) return dp[p][q];
        
        int res = 0;
        
        if(f[p] == s[q])
            res = max(res, 1+ lcs(p + 1, q + 1));
        
         res = max(res, lcs(p, q + 1));
         res = max(res, lcs(p + 1, q));
        
        return dp[p][q] = res;
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        f = word1, s = word2;
        
        return word1.size() + word2.size() - 2 * lcs(0, 0);
    }
};