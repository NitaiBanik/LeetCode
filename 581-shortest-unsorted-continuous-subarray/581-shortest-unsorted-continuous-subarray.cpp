class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> newNums = nums;
        
        sort(nums.begin(), nums.end());
        
        int begin = nums.size(), end = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(newNums[i] != nums[i]){
                begin = min(begin, i);
                end = max(end, i);
            }
        }
        
        return end-begin >= 0 ? end - begin + 1 : 0;
        
    }
};