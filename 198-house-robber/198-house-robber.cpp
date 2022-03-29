class Solution {
public:
    int dp[101];
    
    int fun(int pos, vector<int>& nums){
        if(pos >= nums.size()) return 0;
        
        if(dp[pos] != -1) return dp[pos];
        
        return dp[pos] = max(nums[pos] + fun(pos + 2, nums), fun(pos + 1, nums));
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        
        return fun(0, nums);
    }
};