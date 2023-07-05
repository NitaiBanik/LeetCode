class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cn = 0, ans = 0, prev = 0;
        for(auto n: nums){
            if(n == 1) cn++;
            else{
               ans = max(ans, cn + prev);
                prev = cn;
                cn = 0;
            }
        }
        if(cn == nums.size()) cn--;
        ans = max(ans, cn + prev);
        return ans;
    }
};