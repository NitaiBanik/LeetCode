class Solution {
public:
    int fun(int mask, int picked, vector<int>& nums, vector<int>& dp){
        if(mask == (1 << (nums.size()-1)))
            return 0;
        
        if(dp[mask] != -1) return dp[mask];
        int mx = 0;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(mask & (1 << i)) continue;
                if(mask & (1 << j)) continue;
                
                int newMask = mask | (1 << i) | (1 << j);
                mx = max(mx, __gcd(nums[i], nums[j]) * picked + fun(newMask, picked + 1, nums, dp));
            }
        }
        
        return dp[mask] = mx;
    }
    int maxScore(vector<int>& nums) {
        int num = 1 << nums.size();
        
        vector<int> dp(num + 1, -1);
        
        return fun(0, 1, nums, dp);
    }
};