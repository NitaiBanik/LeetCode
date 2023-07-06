class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int lf = 0, sum = 0, mn = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            
            while(sum >= target){
                mn = min(mn, i - lf + 1);
                sum -= nums[lf++];
            }
        }
        
        return mn == INT_MAX ? 0 : mn;
        
    }
};