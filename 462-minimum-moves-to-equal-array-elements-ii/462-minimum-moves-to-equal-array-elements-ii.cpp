class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int median  = nums[nums.size() / 2];
        long sum = 0;
        
        for(int i = 0; i < nums.size() / 2; i++)
            sum += median - nums[i];
            
        for(int i = nums.size() / 2 + 1; i < nums.size(); i++)
            sum += nums[i] - median;
       return sum;
    }
};