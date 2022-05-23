class Solution {
public:
    int dp[601][101][101];
    vector<pair<int, int>> arr;
    int fun(int pos, int m, int n){
        if(pos == arr.size()) return 0;
        
        if(dp[pos][m][n] != -1) return dp[pos][m][n];
        
        int mx = 0;
        
        if(m - arr[pos].first >= 0  && n - arr[pos].second >= 0)
        mx = max(mx, 1 + fun(pos + 1, m - arr[pos].first, n - arr[pos].second ));
        mx = max(mx, fun(pos + 1, m, n));
        
        return dp[pos][m][n] = mx;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        for(auto s: strs){
            int zero=count(s.begin(),s.end(),'0');
            arr.push_back({zero, s.size() - zero});
        }
        
        memset(dp, -1, sizeof(dp));
        
        return fun(0, m, n);
        
    }
};