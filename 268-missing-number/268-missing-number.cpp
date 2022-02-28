class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
       int totalNumber = nums.size();
        
       int totalSum = (totalNumber * (totalNumber + 1)) /2;
        
       int numsSum = 0;
        
        for(auto num: nums) numsSum += num;
        
        return totalSum - numsSum;
    }
};