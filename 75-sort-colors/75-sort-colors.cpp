class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index = 0;
        
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == 0) swap(nums[index++], nums[i]);
        
        while(index < nums.size() && nums[index] == 0)
            index++;

         for(int i = 0; i < nums.size(); i++)
            if(nums[i] == 1) swap(nums[index++], nums[i]);
    }
};