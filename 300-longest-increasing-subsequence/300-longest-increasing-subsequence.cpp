class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>lis(nums.size(), 10004);
         
         lis[0] = nums[0];
         int pos = 0;
        
        for(int i = 1; i < nums.size(); i++){
            if(lis[pos] < nums[i]){
                pos++;
                 lis[pos] = nums[i];
            }
            else{
                int positionOfEqualImmidiateGraterValue = lower_bound(lis.begin
(), lis.end(), nums[i]) - lis.begin();
                lis[positionOfEqualImmidiateGraterValue] = nums[i];
            }
        }
        
        return pos + 1;
    }
};