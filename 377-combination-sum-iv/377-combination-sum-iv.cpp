class Solution {
public:
    long long combinationWays(vector<int>& nums, vector<long long>& dp, int position, int target){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(position == nums.size()) return 0;
        
        if(dp[target] != -1) return dp[target];
        long long sum1 = combinationWays(nums, dp, 0, target-nums[position]) + combinationWays(nums, dp, position + 1, target);
        
        return dp[target] = sum1;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int size = nums.size();
        vector<long long> dp(target+2, -1);
        
        long long ans = combinationWays(nums, dp, 0, target);
        
        return ans;
    }
};