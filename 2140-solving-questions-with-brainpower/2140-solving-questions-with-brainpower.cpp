class Solution {
public:
    long long fun(int pos, vector<vector<int>>& questions, vector<long long>&dp){
        if(pos >= questions.size()) return 0LL;
        
        if(dp[pos] != -1) return dp[pos];
        
        long long ans1 = 0, ans2 = 0;
        
        ans1 = questions[pos][0] + fun(pos + questions[pos][1] + 1, questions, dp);
        ans2 = fun(pos + 1, questions, dp);
        
        
        return dp[pos] = max(ans1, ans2);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size() + 1, -1);
        
        return fun(0, questions, dp);
    }
};