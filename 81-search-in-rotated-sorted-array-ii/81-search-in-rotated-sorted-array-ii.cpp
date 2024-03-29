class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int beg = 0, end = nums.size() - 1;
        
        if(end < 0) return false;  
        
        while(beg <= end){
            
            int mid = (beg + end) / 2;
            
            if(nums[mid] == target) return true;
            
            if(nums[mid] > nums[beg]){
                if(nums[mid] >= target && target >= nums[beg]) end = mid - 1;
                else beg = mid + 1;
            }
            else if(nums[mid] < nums[beg]){
                if(target >= nums[mid] && target <=  nums[end]) beg = mid + 1;
                else end = mid - 1;
            }
            else{
                beg++;
            }
        }
        return false;
    }
    
};