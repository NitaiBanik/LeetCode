class Solution {
public:
    int lcs(int p, int q, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(p == nums1.size() || q == nums2.size()){
            return 0;
        }
        
        if(dp[p][q] != -1) return dp[p][q];
        
        int mx = 0;
        if(nums1[p] == nums2[q]){
            mx = 1 + lcs(p + 1, q + 1, nums1, nums2, dp);
        }
        
        mx = max(mx, lcs(p, q + 1, nums1, nums2, dp));
        mx = max(mx, lcs(p + 1, q, nums1, nums2, dp));
        
        return dp[p][q] = mx;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp (nums1.size(), vector<int>(nums2.size(), -1));
        
        return lcs(0, 0, nums1, nums2, dp);
    }
};