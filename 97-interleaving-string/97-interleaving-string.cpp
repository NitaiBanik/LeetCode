class Solution {
public:
    int dp[105][105];
    
    bool fun(int x, int y,string s1, string s2, string s3){
        if(x == s1.size() && y == s2.size())
            return 1;
        if(dp[x][y] != -1) return dp[x][y];
        
        int ans = 0;
        
        if(s1[x] == s3[x + y])
            ans |= fun(x+1, y, s1, s2, s3);
        
         if(s2[y] == s3[x + y])
            ans |= fun(x, y + 1, s1, s2, s3);
        
        return dp[x][y]= ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(dp, -1, sizeof(dp));
        
        return fun(0, 0, s1, s2, s3);
    }
};