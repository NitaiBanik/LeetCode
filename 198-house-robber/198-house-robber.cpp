class Solution {
public:
    int fun(int pos, vector<int>& nums, vector<int>& dp){
        if(pos >= nums.size()) return 0;
        
        if(dp[pos] != -1) return dp[pos];
        
        return dp[pos] = max(nums[pos] + fun(pos + 2, nums, dp), fun(pos + 1, nums, dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        
        return fun(0, nums, dp);
    }
};