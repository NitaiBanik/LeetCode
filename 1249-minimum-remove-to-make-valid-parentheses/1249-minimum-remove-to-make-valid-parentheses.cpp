class Solution {
public:
    bool isAlpha(char ch){
        return ch >= 'a' && ch <= 'z';
    }
    string minRemoveToMakeValid(string s) {
        int openParentheses = 0;
        for(int i = 0; i < s.size(); i++){
            if(isAlpha(s[i])) continue;
            if(s[i] == '(') openParentheses++;
            else{
                if(openParentheses > 0){
                    openParentheses--;
                }
                else s[i] = '!';
            }
        }
        
        for(int i = s.size()-1; i >= 0 && openParentheses; i--){
            if(s[i] == '('){
                openParentheses--;
                s[i] = '!';
            }
        }
        
        string ans = "";
        for(int i = 0; i < s.size(); i++)
            if(s[i] != '!') ans+=s[i];
        return ans;
    }
};