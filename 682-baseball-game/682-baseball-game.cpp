class Solution {
public:
    
    void combineValues(stack<long long>& st){
        long long top1 = st.top();
         st.pop();
         
         long long top2 = st.top();
         
         st.push(top1);
         st.push(top1 + top2);
     }
    
    int calPoints(vector<string>& ops) {
        stack<long long> st;
        
        for(auto op: ops){
            if(op == "+"){
                long long top1 = st.top();
                st.pop();
                long long sum = top1 + st.top();
                st.push(top1);
                st.push(sum);
            }
            else if(op == "D"){
                st.push(st.top() * 2);
            }
            else if(op == "C")
                st.pop();
            else
                 st.push(stoi(op));
        }
        
        long long sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};