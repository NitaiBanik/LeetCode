class Solution {
public:
    int dp[105][105][205];
    
    bool fun(int x, int y, int z, string s1, string s2, string s3){
        if(x == s1.size() && y == s2.size())
            return 1;
        if(dp[x][y][z] != -1) return dp[x][y][z];
        
        int ans = 0;
        
        if(s1[x] == s3[z])
            ans |= fun(x+1, y, z + 1, s1, s2, s3);
        
         if(s2[y] == s3[z])
            ans |= fun(x, y + 1, z + 1, s1, s2, s3);
        
        return dp[x][y][z] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(dp, -1, sizeof(dp));
        
        return fun(0, 0, 0, s1, s2, s3);
    }
};