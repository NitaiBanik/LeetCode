class Solution {
public:
    int dp[1002][1002];
    
    int fun(vector<int>& nums, int pos, int remain){
        if(pos == nums.size()-1){
            if(remain == 0) return 0;
            else return 2147483647;
        }
         if(remain == 0){
            if(pos == nums.size()-1) return 0;
            else return 2147483647;
        }
        if(dp[pos][remain] != -1) return dp[pos][remain];
        
        int mn = INT_MAX;
        
        for(int i = pos + 1; i < nums.size(); i++){
            int mx = max(nums[i] - nums[pos], fun(nums, i, remain-1));
            mn = min(mn, mx);
        }
        
        return dp[pos][remain] = mn;
    }
    int splitArray(vector<int>& nums, int m) {
        memset(dp, -1, sizeof(dp));
        nums.push_back(0);
        
        for(int i = nums.size() - 1; i >= 1; i--)
            nums[i] = nums[i-1];
        
         nums[0] = 0;
        
            
       for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i-1];
        
        for(int i = 0; i < nums.size(); i++)
           cout<<nums[i]<<" ";
        
        return fun(nums, 0, m);
    }
};