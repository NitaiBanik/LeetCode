class Solution {
public:
    int fun(vector<int>& nums, vector<vector<int>>& dp, int pos, int remain){
        if(pos == nums.size()-1){
            if(remain == 0) return 0;
            else return INT_MAX;
        }
         if(remain == 0){
            if(pos == nums.size()-1) return 0;
            else return INT_MAX;
        }
        if(dp[pos][remain] != -1) return dp[pos][remain];
        
        int mn = INT_MAX;
        
        for(int i = pos + 1; i < nums.size() - remain + 1; i++){
            int mx = max(nums[i] - nums[pos], fun(nums, dp, i, remain-1));
            mn = min(mn, mx);
        }
        
        return dp[pos][remain] = mn;
    }
    int splitArray(vector<int>& nums, int m) {
        nums.push_back(0);
        
        vector<vector<int>>dp(nums.size(), vector<int>(m + 1, -1));
        
        for(int i = nums.size() - 1; i >= 1; i--)
            nums[i] = nums[i-1];
        
        nums[0] = 0;
        
            
       for(int i = 1; i < nums.size(); i++)
           nums[i] += nums[i-1];
        
        return fun(nums, dp, 0, m);
    }
};