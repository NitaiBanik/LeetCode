class Solution {
public:
    
    int lower_bound(vector<int>&nums, int target){
        
        int position = -1;
        int beg = 0, end = nums.size() -1;
        
        while(beg <= end){
            int mid = (beg + end) / 2;
            
            if(nums[mid] == target){
                position = mid;
                end = mid -1;
            }
            
            else if(nums[mid] < target) beg = mid + 1;
            else end = mid - 1;
        }
        
        return position;
    }
    
  int upper_bound(vector<int>&nums, int target){

    int position = -1;
    int beg = 0, end = nums.size() -1;

    while(beg <= end){
        int mid = (beg + end) / 2;

        if(nums[mid] == target){
            position = mid;
            beg = mid  + 1;
        }

        else if(nums[mid] < target) beg = mid + 1;
        else end = mid - 1;
    }

    return position;
}
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size() == 0) return {-1, -1};
        
        int lowerBound = lower_bound(nums, target);
        if(lowerBound == -1) return {-1, -1};
        
        int upperBound = upper_bound(nums, target);
        return {lowerBound, upperBound};
        
    }
};