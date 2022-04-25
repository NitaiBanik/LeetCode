class Solution {
public:
    int longestValidParentheses(string s) {
        
        int mx = 0, openFromBegin = 0, closeFromBegin = 0, last = s.size() - 1, openFromEnd = 0, closeFromEnd = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') openFromBegin++;
            else closeFromBegin++;
            
            
            if(openFromBegin == closeFromBegin){
                mx = max(mx, openFromBegin + closeFromBegin);
            }
            else if(closeFromBegin > openFromBegin){
                openFromBegin = 0, closeFromBegin = 0;
            }
            
            
            if(s[last--] == '(') openFromEnd++;
            else closeFromEnd++;
            if(openFromEnd == closeFromEnd){
                mx = max(mx, openFromEnd + closeFromEnd);
            }
            else if(closeFromEnd < openFromEnd){
                openFromEnd = 0, closeFromEnd = 0;
            }
        }
        
        return mx;
        
    }
};