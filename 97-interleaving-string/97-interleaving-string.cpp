class Solution {
public:
    int dp[105][105];
    string s3, s1, s2;
    bool fun(int x, int y){
        if(x == s1.size() && y == s2.size())
            return 1;
        if(dp[x][y] != -1) return dp[x][y];
        
        int ans = 0;
        
        if(s1[x] == s3[x + y])
            ans |= fun(x+1, y);
        
         if(s2[y] == s3[x + y])
            ans |= fun(x, y + 1);
        
        return dp[x][y]= ans;
    }
    bool isInterleave(string s11, string s22, string s33) {
        s3 = s33;
        s1 = s11;
        s2 =  s22;
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(dp, -1, sizeof(dp));
        
        return fun(0, 0);
    }
};