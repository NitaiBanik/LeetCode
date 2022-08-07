class Solution {
public:
    //aeiou
    
    int dp[20002][6];
    
    vector<vector<int>> moves = {{1}, {0,2}, {0, 1, 3, 4}, {2, 4}, {0}};
    int mod = 1e9+7;
    
    int permutation(int pos, int vowel){
        if(pos == 0) return 1;
        
    if(dp[pos][vowel] != -1) return dp[pos][vowel];
    
        long long ans = 0; 
        for(int i = 0; i < moves[vowel].size();i++){
            ans += permutation(pos - 1, moves[vowel][i]);
            ans %= mod;
        }
        return dp[pos][vowel] = ans;
    }
    
    int countVowelPermutation(int n) {
        memset(dp, -1, sizeof(dp));
        
        long long ans = 0;
        for(int i = 0; i < 5; i++){
            ans += permutation(n-1, i);
            ans %= mod;
        }
        
        return ans;
    }
};