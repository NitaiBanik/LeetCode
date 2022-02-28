class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        vector<int> trackerNumber(nums.size() + 2, 0);
        
        for(int i = 0; i < nums.size(); i++){
            if((nums[i]> 0) && (nums[i] <= nums.size())){
                trackerNumber[nums[i]] = 1;
            }
        }
        
        for(int i = 1; i <= nums.size() + 2; i++ )
            if(trackerNumber[i] != 1) {
                return i;
            }
        return 1;
    }
};