class Solution {
public:
    int palilndrome(int lf, int rt, string& s, vector<vector<int>>& dp){
        if(lf >= rt) return 1;
        
        if(dp[lf][rt] != -1) return dp[lf][rt];
        
        if(s[lf] == s[rt])
            dp[lf][rt] = palilndrome(lf + 1, rt - 1, s, dp);
        else dp[lf][rt] = 0;
        
        return dp[lf][rt];
    }
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), - 1));
        
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
             count += palilndrome(i, j, s, dp); 
            }
        }
        
        return count;
        
    }
};