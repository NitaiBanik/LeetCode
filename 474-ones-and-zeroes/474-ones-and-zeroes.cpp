class Solution {
public:
    int dp[601][101][101];
    vector<pair<int, int>> oneTwos;
    int fun(int pos, int m, int n){
        if(pos == oneTwos.size()) return 0;
        
        if(dp[pos][m][n] != -1) return dp[pos][m][n];
        
        int mx = 0;
        
        if(m - oneTwos[pos].first >= 0  && n - oneTwos[pos].second >= 0)
        mx = max(mx, 1 + fun(pos + 1, m - oneTwos[pos].first, n - oneTwos[pos].second ));
        mx = max(mx, fun(pos + 1, m, n));
        
        return dp[pos][m][n] = mx;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        for(int i = 0; i < strs.size(); i++){
            int one = 0, zero = 0;
            for(int j = 0; j < strs[i].size(); j++){
                if(strs[i][j] == '1') one++;
                else zero++;
            }
            oneTwos.push_back({zero, one});
        }
        
        memset(dp, -1, sizeof(dp));
        
        return fun(0, m, n);
        
    }
};