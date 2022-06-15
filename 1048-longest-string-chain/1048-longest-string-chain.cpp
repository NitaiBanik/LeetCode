class Solution {
public:
    bool isPredecessor(string s1, string s2){
        int notMatched = 0, pos = 0;
        
        for(int i = 0; i < s2.size(); i++){
            if(s1[pos] != s2[i])
                notMatched++;
            else
                pos++;
            
            if(notMatched > 1) return false;
        }
        
        return true;
    }
   static bool comp(const string& s1, const string& s2){
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        
        vector<int>dp(words.size(), 1);
        int mx = 0;
        
        for(int i = 1; i < words.size(); i++)
            for(int j = 0; j < i; j++){
                int parLen = words[j].size(), childLen = words[i].size();
                
                if((parLen + 1 == childLen) && isPredecessor(words[j], words[i]) && dp[i] < dp[j] + 1)
                    dp[i] = dp[j]  + 1;
                mx = max(mx, dp[i]);
            }
        
        sort(dp.begin(), dp.end());
        
        return dp[words.size() - 1];
    }
};