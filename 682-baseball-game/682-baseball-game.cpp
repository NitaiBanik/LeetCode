class Solution {
public:
    
    stack<long long> combineValues(stack<long long>& st){
        long long top1 = st.top();
         st.pop();
         
         long long top2 = st.top();
         
         st.push(top1);
         st.push(top1 + top2);
         
         return st;
     }
    
    stack<long long> doubleValue(stack<long long>& st){
        long long top1 = st.top();
         st.push(top1 + top1);
        
         return st;
     }
    
    stack<long long> invalidateValue(stack<long long>& st){
        st.pop();
        return st;
     }
    
     stack<long long> addValue(stack<long long>& st, string value){
         int val = stoi(value);
         st.push(val);
         return st;
     }
    
    int calPoints(vector<string>& ops) {
        stack<long long> st;
        
        for(auto op: ops){
             if(op == "+")
                 st = combineValues(st);
            else if(op == "D")
                st = doubleValue(st);
            else if(op == "C")
               st = invalidateValue(st);
            else
                st = addValue(st, op);
        }
        
        long long sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};