class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<long long> st;
        
        for(auto op: ops){
            if(op == "+"){
                st.push_back(st[st.size() - 1]  + st[st.size() - 2]);
            }
            else if(op == "D"){
                st.push_back(st[st.size() - 1]  + st[st.size() - 1]);
            }
            else if(op == "C")
                st.pop_back();
            else
               st.push_back(stoi(op));
        }
        
        long long sum = 0;
        for(int i = 0; i < st.size(); i++)
            sum += st[i];
        
        return sum;
    }
};