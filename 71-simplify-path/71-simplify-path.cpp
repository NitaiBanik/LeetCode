class Solution {
public:
    string simplifyPath(string path) {
        path+='/';
        stack<string>st;
        string temp = "";
        
        for(auto chr: path){
            if(chr == '/'){
                if(temp ==".."){
                    if(!st.empty()) st.pop();
                }
                else if(temp != "/" && temp != "" && temp !="."){
                    st.push(temp);
                } 
                temp="";
            }
            else temp+=chr;
        }
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        return ans == "" 
                ? "/"
                : ans;
            
    }
};