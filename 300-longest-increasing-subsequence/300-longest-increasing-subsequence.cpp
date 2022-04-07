class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size(), 0);
        
        dp[0] = 1;
        int mx = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = i - 1; j >=0; j--){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[j], dp[i]);
            }
        
          dp[i] += 1;
           mx = max(mx, dp[i]);
        }
        return mx;
    }
};