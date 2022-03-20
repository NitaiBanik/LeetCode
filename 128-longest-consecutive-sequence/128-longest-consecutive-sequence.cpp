class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       set<int>st;
        
        int ans = 0;
        for(auto num: nums) st.insert(num);
        for(auto num: nums){
            if(st.find(num-1) == st.end()){
                int cnt = 1;
                int n = num;
                
                while(st.find(n + 1) != st.end()) { n++,cnt++;}
                
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};