class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        
        int ans = 0;
        int consecutiveNumbers = 0;
        for(int i = 2; i < nums.size(); i++){
            if((nums[i-2] - nums[i-1]) == (nums[i-1] - nums[i])){
                consecutiveNumbers++;
                ans+=consecutiveNumbers;
            }
            else{
                consecutiveNumbers = 0;
            }
        }
        
        return ans;
    }
};