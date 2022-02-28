class Solution {
public:
    bool isIncreasing(vector<int>&nums){
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i + 1] < nums[i])
                return false;
        }
        return true;
    }
    
    bool isDecreasing(vector<int>&nums){
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i + 1] > nums[i])
                return false;
        }
        return true;
    }
    
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1) return true;
        
        bool answer = false;
        answer |= isIncreasing(nums);
        answer |= isDecreasing(nums);
        
        return answer;
    }
};