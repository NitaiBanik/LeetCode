class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<char> st;
        
        st.push(colors[0]);
        
        int sum = 0;
        int currentSum = neededTime[0], mn = neededTime[0];
        
        for(int i = 1; i < neededTime.size(); i++){
            if(st.top() == colors[i]){
                currentSum += neededTime[i];
                mn = max(mn, neededTime[i]);
            }
            else{
                sum += currentSum;
                sum -= mn;
                
                st.push(colors[i]);
                
                mn = neededTime[i];
                currentSum = mn;
            }
        }
        
        sum += currentSum;
        sum -= mn;
        
        return sum;
    }
};