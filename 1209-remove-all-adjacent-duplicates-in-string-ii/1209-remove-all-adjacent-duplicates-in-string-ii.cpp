class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<int,char>>st;
        int cnt = 0;
        for(auto chr: s){
            
            if(!st.empty() && st.top().second == chr){
                cnt = st.top().first + 1;
                st.push({cnt, chr});
            }
            else {
                st.push({1,chr});
                cnt = 1;
            }
            
            
            if(cnt >= k){
                int j = k;
                while(j--) st.pop();
            }
        }
        string str = "";
        while(!st.empty())
        {
            str += st.top().second;
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};