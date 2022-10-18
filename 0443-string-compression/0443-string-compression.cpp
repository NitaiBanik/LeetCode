class Solution {
public:
    int compress(vector<char>& chars) {
        stack<char>st;
        st.push(chars[0]);
        
        int pos=0, cnt = 1;
        
        for(int i = 1; i < chars.size(); i++){
            if(st.top() == chars[i]) cnt++;
            else{
                char val = st.top();
                st.pop();
                st.push(chars[i]);
                
                chars[pos++] = val;
                if(cnt > 1){
                    string num =  to_string(cnt);
                    for(int i = 0; i < num.size(); i++){
                        chars[pos++] = num[i];
                    }
                }
                cnt = 1;
            }
        }
        
        chars[pos++] = st.top(); 
        if(cnt > 1){
            string num =  to_string(cnt);
            for(int i = 0; i < num.size(); i++){
                chars[pos++] = num[i];
            }
        }
        return pos;
    }
};