class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closingParentheses;
        
        closingParentheses[')'] = '(';
        closingParentheses['}'] = '{';
        closingParentheses[']'] = '[';
        
        stack<char>openParentheses;
        
        for(auto parentheses : s){
            if(!openParentheses.empty() && openParentheses.top() == closingParentheses[parentheses])
                openParentheses.pop();
            else openParentheses.push(parentheses);
        }
       return openParentheses.empty();
    }
};