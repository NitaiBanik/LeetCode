class Solution {
public:
    int longestValidParentheses(string s) {
        
        int mx = 0, open = 0, close = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') open++;
            else close++;
            
            if(open == close){
                mx = max(mx, open + close);
            }
            else if(close > open){
                open = 0, close = 0;
            }
        }
        
        open = 0, close = 0;
        
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '(') open++;
            else close++;
            
            if(open == close){
                mx = max(mx, open + close);
            }
            else if(close < open){
                open = 0, close = 0;
            }
        }
        
        return mx;
        
    }
};