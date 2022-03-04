class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int currentjump = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            if(i <= currentjump)
                currentjump = max(currentjump, i + nums[i]);
            
            if(currentjump >=(nums.size() -1)) return true;
        }
        
        return false;
        
    }
};