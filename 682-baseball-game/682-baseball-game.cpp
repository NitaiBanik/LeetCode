class Solution {
public:
    
    void combineValues(stack<long long>& st){
        long long top1 = st.top();
         st.pop();
         
         long long top2 = st.top();
         
         st.push(top1);
         st.push(top1 + top2);
     }
    
    void doubleValue(stack<long long>& st){
        long long top1 = st.top();
         st.push(top1 + top1);
     }
    
    void invalidateValue(stack<long long>& st){
        st.pop();
     }
    
     void addValue(stack<long long>& st, string value){
         int val = stoi(value);
         st.push(val);
     }
    
    int calPoints(vector<string>& ops) {
        stack<long long> st;
        
        for(auto op: ops){
            if(op == "+")
                combineValues(st);
            else if(op == "D")
                doubleValue(st);
            else if(op == "C")
                invalidateValue(st);
            else
                 addValue(st, op);
        }
        
        long long sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};