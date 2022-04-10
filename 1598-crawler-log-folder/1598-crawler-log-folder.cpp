class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        vector<string>st;
        
        for(auto log: logs){
            if(log == "../"){
                if(st.size()) st.pop_back();
            }
            else if(log != "./")
                st.push_back(log);
        }
        return st.size();
    }
};