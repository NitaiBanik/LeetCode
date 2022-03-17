class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        for(auto chr: s){
            if(chr == '(') st.push(0);
            else{
                int currValue = st.top();
                st.pop();
                int prevValue = 0;
                if(!st.empty()){
                prevValue = st.top();
                st.pop();
                }
                st.push(prevValue + max(2 * currValue, 1));
            }
        }
        return st.top();
        
    }
};