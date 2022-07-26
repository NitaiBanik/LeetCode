class Solution {
public:  
    int characterReplacement(string s, int k) {
        int ans = 0, lf = 0, mx = 0;
        int frequency[130];
        memset(frequency, 0, sizeof(frequency));
        
        for(int i = 0; i < s.size() && lf < s.size(); i++){
            frequency[s[i]]++;
            
            mx = max(frequency[s[i]], mx);
            
            if((i - lf + 1 - mx) <= k) ans = max(ans, i - lf + 1);
            else {
                frequency[s[lf]]--;
                lf++;
            }
        }
        
        return ans;
    }
};
    