class Solution {
public:
    string countAndSay(int n) {
        string num= "1";
        n--;
        while(n--){
            string temp = "";
            
            int cnt = 1;
            stack<char>st;
            st.push(num[0]);
            
            for(int i = 1; i < num.size(); i++){
                if(st.top() == num[i]) cnt++;
                else{
                    char val = st.top();
                    st.pop();
                    st.push(num[i]);
                    temp += to_string(cnt) + val;
                    cnt = 1;
                }
            }
            temp += to_string(cnt) + st.top();
            num = temp;
        }
       return num; 
    }
};