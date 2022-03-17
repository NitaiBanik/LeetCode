class Solution {
public:
    int scoreOfParentheses(string s) {
        char previousCharacter;
        int ans = 0;
        int bracket = 0;
        
        for(auto chr: s){
            if(chr == '(') bracket++;
            else{
                bracket--;
                if(previousCharacter == '(') ans += (1 << bracket);
            }
            previousCharacter = chr;
        }
        return ans;
    }
};