class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int arr[10003] = {0};
        
        for(auto num: nums){
            arr[num]++;
        }
        
        int dp[10003] = {0};
        dp[0] = 0;
        dp[1] = arr[1] * 1;
        
        for(int i = 2; i <= 10000; i++){
            dp[i] = max(dp[i-1], dp[i-2] + arr[i] * i);         
        }
        
        return dp[10000];
    }
};