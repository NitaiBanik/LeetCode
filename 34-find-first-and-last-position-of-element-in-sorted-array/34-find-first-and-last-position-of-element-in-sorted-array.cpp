class Solution {
public:
    int find(vector<int>& nums, int target){
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            
            if(nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        
        int pos1 = find(nums, target);
        cout<<"pos ="<<pos1<<endl;
        if(pos1 >= nums.size() || nums[pos1] != target) return {-1, -1};
        
        if(pos1 == nums.size() - 1)
            return {pos1, pos1};
        
        int pos2 = find(nums, target+1) -1;   
        if(nums[pos2] != target) return {pos1, pos1};
        
        return {pos1, pos2};
    }
};