class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        
        for(auto num: nums){
            if(num){
                nums[pos++] = num;
            }
        }
        
        for(int i = pos; i < nums.size(); i++) 
            nums[i] = 0;
    }
};