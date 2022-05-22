class Solution {
public:
    int countSubstrings(string s) {
        
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            int lf = i, rt = i;
            while(lf >= 0 && rt < s.size() && s[lf] == s [rt]){
                count++;
                lf--, rt++;
            }
            
            lf = i, rt = i + 1;
            while(lf >= 0 && rt < s.size() && s[lf] == s [rt]){
                count++;
                lf--, rt++;
            }
        }
        
        return count;
        
    }
};