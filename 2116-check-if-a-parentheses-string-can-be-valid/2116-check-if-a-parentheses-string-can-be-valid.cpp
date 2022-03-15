class Solution {
public:
    bool canBeValid(string s, string locked) {
        cout<<s.size()<<endl;
        if(s.size() % 2) return false;
        
        stack<char>st; 
        int cn = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(locked[i] == '1'){
                if(s[i] == '(') st.push(s[i]);
                else if(!st.empty()) st.pop();
                else if(cn > 0){cn--;}
                else return false;
            }
            else cn++;
        }
        cn = 0;
        stack<char>st2; 
        for(int i = s.size() - 1; i >= 0; i--){
            if(locked[i] == '1'){
                if(s[i] == ')') st2.push(s[i]);
                else if(!st2.empty()) st2.pop();
                else if(cn > 0){cn--;}
                else return false;
            }
            else cn++;
        }
        return true;
    }
};