class Solution {
public:
    
    int lower_bound(vector<int>&nums, int target){
        
        int beg = 0, end = nums.size() -1;
        
        while(beg <= end){
            int mid = (beg + end) / 2;
            
            if(nums[mid] < target) beg = mid + 1;
            else end = mid - 1;
        }
        
        return beg;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size() == 0) return {-1, -1};
        
        int lowerBound = lower_bound(nums, target);
        if(lowerBound >= nums.size() || nums[lowerBound] != target) return {-1, -1};
        
        int upperBound = lower_bound(nums, target + 1) - 1;
        return {lowerBound, upperBound};
        
    }
};