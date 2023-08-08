class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int sz = nums.size();
        
        if(sz == 0) return -1;
        
        int lo = 0, hi = sz - 1;
        
        while(lo<=hi)
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] == target) return mid;
            
            else if(nums[0]<=nums[mid])
            {
                if(target >= nums[0] && nums[mid]>=target)
                    hi=mid-1;
                else lo = mid + 1;
            }
            else
            {
                if(nums[mid]<=target && target <= nums[sz-1])
                    lo=mid+1;
                else hi = mid - 1;
            }
        }
        return -1;
        
    }
};