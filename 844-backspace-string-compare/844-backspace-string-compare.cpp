class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s_Stack, t_Stack;
        
        for(auto chr: s){
            if(chr != '#')
                s_Stack.push(chr);
            else if(!s_Stack.empty())
                s_Stack.pop();
        }
        for(auto chr: t){
            if(chr != '#')
                t_Stack.push(chr);
            else if(!t_Stack.empty())
                t_Stack.pop();
        }
        
        
        return s_Stack == t_Stack;
    }
};