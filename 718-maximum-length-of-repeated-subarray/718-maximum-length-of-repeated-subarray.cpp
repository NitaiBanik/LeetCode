class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        
        int mx = 0;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(i == 0 || j == 0){
                    if(nums1[i] == nums2[j])
                        dp[i][j] = 1;
                }
                else{
                    if(nums1[i] == nums2[j])
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                mx = max(mx, dp[i][j]);
            }
        }
        return mx;
    }
};