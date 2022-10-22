class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> freqT(126, 0);
        vector<int> freqS(126, 0);
        int unique = 0;
        
        for(auto chr: t){
            freqT[chr]++;
            if(freqT[chr] == 1) unique++;
        }
        
        int lf = 0, cnt = 0, ln = 999999, l = -1, r = -1;
        
        for(int i = 0; i < s.size(); i++){
            freqS[s[i]]++;
            if(freqS[s[i]] == freqT[s[i]]) cnt++;
            while(cnt == unique && lf < s.size()){
               if(ln > (i - lf + 1)){
                   ln = i - lf + 1, l = lf, r = i;
               }
                if(freqS[s[lf]] == freqT[s[lf]]) cnt--;
                freqS[s[lf++]]--;
            }
        }
        if(l == -1) return "";
        string ans = "";
        for(int i = l; i <= r; i++) ans += s[i];
     return ans;
    }
};