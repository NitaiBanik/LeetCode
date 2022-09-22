class Solution {
public:
    string reverseWords(string s) {
        int lf = 0, rt = 0;
        
        for(rt = 0; rt < s.size(); rt++){
            if(s[rt] == ' '){
                for(int j = 0; j < (rt - lf) / 2; j++){
                    swap(s[lf + j], s[rt - j -1]);
                }
                
                lf = rt + 1;
            }
        }
        
        for(int j = 0; j < (rt - lf) / 2; j++){
            swap(s[lf + j], s[rt - j-1]);
        }
            return s;
    }
};