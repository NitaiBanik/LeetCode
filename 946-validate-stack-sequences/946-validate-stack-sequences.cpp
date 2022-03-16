class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int start = 0;
        for(auto val: pushed){
            st.push(val);
         while(!st.empty() && st.top() == popped[start]){
             st.pop();
             start++;
         }   
        }
         while(!st.empty() && st.top() == popped[start]){
             st.pop();
             start++;
         } 
        
        return start == popped.size();
        
    }
};